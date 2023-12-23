/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmouto <kelmouto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:11:33 by kelmouto          #+#    #+#             */
/*   Updated: 2023/12/22 21:18:35 by kelmouto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <stdexcept> 
#include<iostream>
#include<utility>
#include<exception>
#include <algorithm>
#include<stack>
#include<vector>
#include<deque>

typedef struct element
{
    int nb;
    std::vector<int>index;
     element()
     {    
     }
    element(const element &obj)
    {
        nb = obj.nb;
        index = obj.index;
    }
    struct element *next;
    bool operator<(const element& other) const {
        return nb < other.nb;}
}element;

class PmergeMe
{
    private:
        std::vector<element> myVector;
        std::vector<element>Store;
        std::deque<element> mydeQue;
        std::deque<element>Stock;
 
    public:
        PmergeMe();
        PmergeMe& operator=(const PmergeMe& other);
        PmergeMe(const PmergeMe& other);
        ~PmergeMe();
        void doSortVect(std::vector<element> v);
        void doMergeSort(char **arr);
        void doSortDeque(std::deque<element> d);
        void printVector(std::vector<element> v);
};
#endif 