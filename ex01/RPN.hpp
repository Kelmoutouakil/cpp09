/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmouto <kelmouto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:17:35 by kelmouto          #+#    #+#             */
/*   Updated: 2023/12/12 14:07:53 by kelmouto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP
#include <stdexcept> 
#include <iostream>
#include <fstream>
#include<exception>
#include <algorithm>
#include<stack>
#include<sstream>

class RPN
{
    private:
        std::stack<int>myStack;
      public:
        int splitInput(std::string& s);

        
    
};





#endif