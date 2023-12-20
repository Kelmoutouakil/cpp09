/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmouto <kelmouto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:12:46 by kelmouto          #+#    #+#             */
/*   Updated: 2023/12/20 16:47:55 by kelmouto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include<cmath>
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
    // std::vector<element>::iterator ps = Store.begin();
    //     for (; ps != Store.end(); ++ps)
    //         std::cout << ps->nb << " _ ";
    //     std::cout << "\n";
    if (std::is_sorted(Store.begin(), Store.end()))
        std::cout << "yes\n";
    else   
        std::cout << "no\n";
}

void PmergeMe::doMergePair(std::vector<element> v)
{
    std::vector<std::pair<element, element> > myVectorOfPairs;
    std::vector<element> temp;
int j = 0;
    for (std::vector<element>::iterator it = v.begin(); it != v.end() && (it + 1) != v.end();) 
    {
        it->index.push_back(j);
        (it + 1)->index.push_back(j);
        if( it-> nb > (it + 1)->nb )
            std::swap(*it , *(it + 1));
        myVectorOfPairs.push_back(std::make_pair(*it, *(it + 1)));
        temp.push_back(*(it + 1));
        
        // if (it->nb < (it + 1)->nb)
        // {
        //     myVectorOfPairs.push_back(std::make_pair(*it, *(it + 1)));
        //     temp.push_back(*(it + 1));
        // }
        // else
        // {
        //     myVectorOfPairs.push_back(std::make_pair( *(it + 1), *it));
        //     temp.push_back(*it);
        // }
       // std::cout << "index :" << temp.back().index.back() ;
        it += 2;
        j++;
    }
    std::cout << "\n";
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
        std::cout<< " size of index : " << p->index.size() <<"\n";
        int a = p->index.back();
        if (p->nb == 64)
            std::cout << "\nindex two:" << myVectorOfPairs[a].first.index.back();
            
        myVectorOfPairs[a].first.index.pop_back();
        p->index.pop_back();
        s.push_back(myVectorOfPairs[a].first);
    }
    std::cout<< "\n";
    // std::cout << "pairs: " ;
    // for ( std::vector<std::pair<element,element> >::iterator iter = myVectorOfPairs.begin(); iter != myVectorOfPairs.end(); iter++)
    // {
    //     std::cout << "("<<iter->first.nb << "idx:" << iter->first.index.back() << "," << iter->second.nb << "idx:" << iter->second.index.back() <<") ";
    // }
    std::cout << "\n";
    std::vector<element>::iterator ss = s.begin();
    std::cout << "small: " ;
    for (; ss !=s.end(); ++ss)
        std::cout << ss->nb << "; ";
    std::cout << "\n";
    ss = Store.begin();
    std::cout << "big  : " ;
    for (; ss != Store.end(); ++ss)
        std::cout << ss->nb << "; ";
    std::cout << "\n";
    int k = 0;
    for (std::vector<element>::iterator ps = s.begin(); ps != s.end(); ++ps) 
    {
  //  int r =distance(Store.begin(), ps);
    std::vector<element>::iterator step = Store.begin() +( k + k   );
    std::cout <<"insert : "<< ps->nb << " , " << "step :  "<< step->nb  << "\n";
    std::vector<element>::iterator is = std::lower_bound(Store.begin(), step, *ps);
    Store.insert(is, *ps);
    k++;
    } 

    std::cout<< "\n";
    if(v.size() % 2 != 0)
    {
        std::vector<element>::iterator is = std::lower_bound(Store.begin(), Store.end(), v.back());
        Store.insert(is, v.back());
    }
    }

int main(int argc, char  *argv[])
{   
    try
    {
        PmergeMe o;
        std::vector<std::pair<int, int> >vect;
        if(argc != 1)
            o.StoreVect(argv);
        else
            throw std::invalid_argument("invalid arguments!");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
