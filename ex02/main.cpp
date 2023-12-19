/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmouto <kelmouto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:12:46 by kelmouto          #+#    #+#             */
/*   Updated: 2023/12/19 14:57:32 by kelmouto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
void PmergeMe::StoreVect(char **arr)
{
    int i = 1;

    while (arr[i])
    {
        element newData;
        newData.nb = atoi(arr[i]);
        newData.next = NULL; 
        myVector.push_back(newData);
        data.next = &myVector.back();
        data = myVector.back();
        i++;
    }
    this->doMergePair(myVector);
    std::vector<element>::iterator ps = Store.begin();
        for (; ps != Store.end(); ++ps)
            std::cout << ps->nb << " _ ";
        std::cout << "\n";
    if (std::is_sorted(Store.begin(), Store.end()))
        std::cout << "yes\n";
    else   
        std::cout << "no\n";
}

void PmergeMe::doMergePair(std::vector<element>& v)
{
    std::vector<std::pair<element, element> > myVectorOfPairs;
    std::vector<element> temp;

    for (std::vector<element>::iterator it = v.begin(); it != v.end() && (it + 1) != v.end();) {
        if (it->nb > (it + 1)->nb)
        {
            std::swap(it->nb, (it + 1)->nb);
        } 
        myVectorOfPairs.push_back(std::make_pair(*it, *(it + 1)));
        it += 2;
    }
    int j = 0;
    for (std::vector<std::pair<element, element> >::iterator i = myVectorOfPairs.begin(); i != myVectorOfPairs.end(); ++i)
    {
        i->first.index.push_back(j);
        i->second.index.push_back(j);
        temp.push_back(i->second);
        j++;
    }
        if (v.size() > 1) 
            this->doMergePair(temp);
        else 
        {
            Store.push_back(*(v.begin()));
            return;
        }


        std::vector<element> s;
        for (std::vector<element>::iterator p = Store.begin(); p != Store.end(); ++p)
        {
            int a = p->index.back();
            myVectorOfPairs[a].first.index.pop_back();
            p->index.pop_back();
            s.push_back(myVectorOfPairs[a].first);
        }
        std::vector<element>::iterator ps = s.begin();
        int k = 0;
        for (; ps != s.end(); ++ps) 
        {
            std::vector<element>::iterator step = Store.begin() + k + k;
            if (step > Store.end())
            {
                step = Store.end();
            }
            std::vector<element>::iterator is = std::lower_bound(Store.begin(), step , *ps);
            Store.insert(is, *ps);
            k++;
        }
        if(v.size() % 2 != 0)
        {
            std::vector<element>::iterator is = std::lower_bound(Store.begin(), Store.end(), v.back());
            Store.insert(is, v.back());
        }
        // std::cout << std::endl;

        
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
