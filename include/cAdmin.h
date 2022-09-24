/********************************************************************************************************************************************
Author: 	 Mohamed Shawky Ahmed
Description: Bank Management System - C++ based-OOP console project providing some admin and user commands.
Version:     01
file:        cAdmin.h
Date:        31/08/2022
*********************************************************************************************************************************************/
#ifndef _CADMIN_H
#define _CADMIN_H

#include "STD_TYPES.h"

class cAdmin : public cClient{

	public:
		/* Constructor */
		cAdmin();

		/* APIs */
		void change_account_status(std::string);
		void make_transaction(u32, u64);	
		
};


/* This function return specified client if exists using id */ 
cAdmin& get_admin(u32 id);

#endif	/* _CADMIN_H */