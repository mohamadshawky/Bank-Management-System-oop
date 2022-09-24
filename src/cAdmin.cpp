/********************************************************************************************************************************************
Author: 	 Mohamed Shawky Ahmed
Description: Bank Management System - C++ based-OOP console project providing some admin and user commands.
Version:     01
file:        cAdmin.cpp
Date:        31/08/2022
*********************************************************************************************************************************************/
#include "../include/STD_TYPES.h"

#include <iostream>
#include <string>
#include <time.h>

#include "../include/cClient.h"
#include "../include/cAdmin.h"

/* Global data */
cAdmin admins[50];
u32 admins_size;

/* Constructor */
cAdmin::cAdmin(){}

/* This fuction set the account satuts */		
void cAdmin::change_account_status(std::string status){
	
	if (get_account_status() == "active")
	{	
	if(status == "active")
	{
		change_acc_status("active");
		std::cout << " Account ID " 
				  << get_account_id()
				  << " status becomes "
				  << get_account_status()
				  << std::endl;
	}
	else if (status == "restricted")
	{
		change_acc_status("restricted");
		std::cout << " Account ID " 
				  << get_account_id()
				  << " status becomes "
				  << get_account_status()
				  << std::endl;
	}
	else if (status == "closed")
	{
		change_acc_status("closed");
		std::cout << " Account ID " 
				  << get_account_id()
				  << " status becomes "
				  << get_account_status() 
				  << std::endl;
	}
	else
		{
		std::cout << "\n>> Invalid Input!"
				  << std ::endl;
		}
	}
	else
	{
		std::cout << " Account ID "  
				  << " does not exist! " 
				  << std::endl;
	}	
}

/* This function inputs account id 1, account id 2 & balance to transfer */
void cAdmin::make_transaction(u32 id, u64 balance){
	cAdmin admin = get_admin(id);
	if ((admin.get_account_status() == "active") && (get_account_status() == "active") && (balance <= get_account_balance())){
		admin.add_acc_balance(balance);
		this->sub_acc_balance(balance);
		std::cout << " Account ID "<< id << " balance = " << admin.get_account_balance() << std::endl;
		std::cout << " Account ID "<< get_account_id() <<" balance = " << get_account_balance() << std::endl;
	}
	else{
		std::cout << " Sorry! "
				  << std::endl
				  << " Account ID "
				  << get_account_id()
				  << " has not sufficient balance or "
				  << " any of account ID "
				  << get_account_id()  
				  << " or ID " 
				  << id 
				  << " is not active."
				  << std::endl;
  }
}


cAdmin& get_admin(u32 id){
	for (u32 i = 0; i < admins_size; i++){				
			if (admins[i].get_account_id() == id){
				return admins[i];} 	
	}	
}