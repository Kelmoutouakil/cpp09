/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmouto <kelmouto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:12:46 by kelmouto          #+#    #+#             */
/*   Updated: 2023/12/14 12:30:27 by kelmouto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
void PmergeMe:: StoreVect(char **arr)
{
    int i = 1;
    while(arr[i])
    {
        myVector.push_back(atoi(arr[i]));
        i++;
    }
}
std::vector<std::pair<int, int> >  PmergeMe:: doMergePair()
{
    std::vector<std::pair<int, int> > myVectorOfPairs;
    if(myVector.size()% 2 != 0)
        impair = 1;
    std::vector<int>::iterator it = myVector.begin();
    std::vector<int>::iterator ite = myVector.end();
    if(impair == 1)
        ite--;  
    for (; it != ite; ++it)
        myVectorOfPairs.push_back(std::pair<int,int>(*it, *(++it)));
    return(myVectorOfPairs);
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
            vect = o.doMergePair();
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
