/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmouto <kelmouto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 09:44:20 by kelmouto          #+#    #+#             */
/*   Updated: 2023/12/20 19:09:14 by kelmouto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <stdexcept> 
#include <iostream>
#include <fstream>
#include<exception>
#include<map>
#include <algorithm>
class BitcoinExchange
{
    private:
        std::map<int,double>myMap;
        std::string sDate;
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        void StoreMap();
        int dateFormat(std::string& s);
        double valueFormat(std::string& str);
        void CoinExchange(int date,double value);
};

bool isLeapYear(int year) ;


#endif