/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmouto <kelmouto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:12:46 by kelmouto          #+#    #+#             */
/*   Updated: 2023/12/15 14:02:13 by kelmouto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
void PmergeMe:: StoreVect(char **arr)
{
    int i = 1;
    while(arr[i])
    {
        element* newData = new element;
        newData->nb = atoi(arr[i]);
        newData->next = NULL;
        myVector.push_back(*newData);
        data->next = newData;
        data = newData;
        i++;
    }
    this->doMergePair(myVector);
}
void PmergeMe::doMergePair(std::vector<element> &v)
{
    std::vector<std::pair<element, element> > myVectorOfPairs;
    std::vector<element> temp;
    if (v.size() % 2 != 0)
        impair = 1;
    std::vector<element>::iterator it = v.begin();
    std::vector<element>::iterator ite = v.end();
    if (impair == 1)
        ite--;
    int j = 1;
    for (; it != ite; ++it)
    { 
       if(it->nb > (it + 1)->nb)
       {
        int tmp = it->nb;
        it->nb = (it + 1)->nb;
        (it + 1)->nb = tmp;
       }
        myVectorOfPairs.push_back(std::pair<element, element>(*it, *(++it)));
    }
    std::vector<std::pair<element, element> >::iterator i = myVectorOfPairs.begin();
    for (; i != myVectorOfPairs.end(); ++i)
    {
        i->first.index = i->second.index = j;
        j++;
        temp.push_back(i->second);// std::cout << i->first.nb << "** "<<i->first.index << " " << i->second.nb << "**"<< i->second.index << std::endl;
    }
    if(temp.size() > 1)
        this->doMergePair(temp);
    std::vector<element>::iterator ptr = temp.begin();
    Store.push_back(*ptr);
}





int main(int argc, char  *argv[])
{   
    try
    {
        PmergeMe o;
        std::vector<std::pair<int, int> >vect;
        if(argc != 1)
        {
            o.StoreVect(argv);
            
            //  std::vector<std::pair<int, int> >::iterator i = vect.begin();
            //  for(;i != vect.end() ; ++i)
            //     std::cout<< i->first << "---"<< i->second << "\n";
        }
        else
            throw std::invalid_argument("invalid arguments!");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
