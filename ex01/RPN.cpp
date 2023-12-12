/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmouto <kelmouto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:46:01 by kelmouto          #+#    #+#             */
/*   Updated: 2023/12/12 14:54:27 by kelmouto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"RPN.hpp"

int RPN::splitInput(std::string& s) 
{
   std::stringstream ss(s);
   char c;
   int tmp1;
   int tmp2;
   int result;
   while(ss >> c)
   {
      if(std::isdigit(c))
         myStack.push(c - '0');
      else if( c == '*' || c =='-' || c == '+' || c == '/')
      {
         if(myStack.size() < 2)
            throw std::runtime_error("Error");
         tmp1 = myStack.top();
         myStack.pop();
         tmp2 = myStack.top();
         myStack.pop();
         if( c == '*')
            result = tmp2 * tmp1;
         if(c == '-')
            result = tmp2 - tmp1;
         if(c == '+')
            result = tmp2 + tmp1;
         if(c == '/')
         {
            if(!tmp1)
               throw std::runtime_error("Error in fraction");
            result = tmp2 / tmp1;
         }
          myStack.push(result);  
      }
      else
         throw std::runtime_error("Error");
   }
    return myStack.top();
}



