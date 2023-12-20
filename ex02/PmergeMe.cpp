/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmouto <kelmouto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:12:30 by kelmouto          #+#    #+#             */
/*   Updated: 2023/12/20 18:57:24 by kelmouto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
        

PmergeMe::PmergeMe()
{
}
PmergeMe :: ~PmergeMe()
{
    
}
PmergeMe::PmergeMe(const PmergeMe& other)
{
    *this = other;
}
PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if(this != &other)
    {
        mydeQue = other.mydeQue;
        myVector = other.myVector;
        Stock= other.Stock;
        Store = other.Store;
    }
    return(*this);
}

void PmergeMe:: printVector(std::vector<element> v)
{
    std::vector<element>::iterator iter = v.begin();
    for(;iter != v.end();++iter)
        std::cout<< iter->nb << " ";
    std::cout<<std::endl;
}

void printDeque(std::deque<element> d)
{
     std::deque<element>::iterator iter = d.begin();
    for(;iter != d.end();++iter)
        std::cout<< iter->nb << " ";
    std::cout<<std::endl;
}

void PmergeMe::doMergeSort(char **arr)
{
    int i = 1;
    std::string s ;
    while (arr[i])
    {
        element newData;
        s = arr[i];
        // std::cout <<"--->" <<s << "\n";
        // if(s.find_first_not_of("012345678") != std::string::npos)
        //     throw std::runtime_error("Error: positive sequence required ");
        newData.nb = atoi(arr[i]);
        newData.next = NULL; 
        myVector.push_back(newData);
        mydeQue.push_back(newData);
        i++;
    }
    std::cout<< "Before: ";
    printVector(myVector);
    clock_t start = clock();
    this->doSortVect(myVector);
    clock_t end = clock();
    double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    std::cout<< "After: ";
    printVector(Store); 
    std::cout<< "Time to process a range of " << myVector.size()<<" elements with std::vector is : "<< duration<< std::endl;
    start = clock();
    this->doSortDeque(mydeQue);
    end = clock();
     duration = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    std::cout<< "Time to process a range of "<< mydeQue.size()<<" elements with std::deque  is : "<< duration<< std::endl;
}

void PmergeMe::doSortVect(std::vector<element> v)
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
        it += 2;
        j++;
    }
    if (v.size() > 1) 
        this->doSortVect(temp);
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
    int k = 0;
    for (std::vector<element>::iterator ps = s.begin(); ps != s.end(); ++ps) 
    {
        std::vector<element>::iterator step = Store.begin() + 2 * k;
        std::vector<element>::iterator is = std::lower_bound(Store.begin(), step, *ps);
        Store.insert(is, *ps);
        k++;
    } 
    if(v.size() % 2 != 0)
    {
        std::vector<element>::iterator is = std::lower_bound(Store.begin(), Store.end(), v.back());
        Store.insert(is, v.back());
    }
}
 
void PmergeMe:: doSortDeque(std::deque<element> d)
{
    std::deque<std::pair<element, element> > myVectorOfPairs;
    std::deque<element> temp;
    int j = 0;
    for (std::deque<element>::iterator it = d.begin(); it != d.end() && (it + 1) != d.end();) 
    {
        it->index.push_back(j);
        (it + 1)->index.push_back(j);
        if( it-> nb > (it + 1)->nb )
            std::swap(*it , *(it + 1));
        myVectorOfPairs.push_back(std::make_pair(*it, *(it + 1)));
        temp.push_back(*(it + 1));
        it += 2;
        j++;
    }
    if (d.size() > 1) 
        this->doSortDeque(temp);
    else 
    {
        Stock.push_back(*(d.begin()));
        return;
    }
    std::deque<element> s;
    for (std::deque<element>::iterator p = Stock.begin(); p != Stock.end(); ++p)
    {
        int a = p->index.back();
        myVectorOfPairs[a].first.index.pop_back();
        p->index.pop_back();
        s.push_back(myVectorOfPairs[a].first);
    }
    int k = 0;
    for (std::deque<element>::iterator ps = s.begin(); ps != s.end(); ++ps) 
    {
        std::deque<element>::iterator step = Stock.begin() + 2 * k;
        std::deque<element>::iterator is = std::lower_bound(Stock.begin(), step, *ps);
        Stock.insert(is, *ps);
        k++;
    } 
    if(d.size() % 2 != 0)
    {
        std::deque<element>::iterator is = std::lower_bound(Stock.begin(), Stock.end(), d.back());
        Stock.insert(is, d.back());
    }
}