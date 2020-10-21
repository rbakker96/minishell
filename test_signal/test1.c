/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test1.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qli <qli@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/20 17:22:47 by qli           #+#    #+#                 */
/*   Updated: 2020/10/20 17:24:34 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// CPP program to illustrate 
// User-defined Signal Handler 
#include<stdio.h> 
#include<signal.h> 
  
// Handler for SIGINT, caused by 
// Ctrl-C at keyboard 
void handle_sigint(int sig) 
{ 
    printf("Caught signal %d\n", sig); 
} 
  
int main() 
{ 
    signal(SIGINT, handle_sigint); 
    while (1) ; 
    return 0; 
} 
