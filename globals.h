#ifndef _GLOBALS_H
#define _GLOBALS_H

//--------------------------------------------------------------------
// Include Files
#include "lrun.h"
#include "web_api.h"
#include "lrw_custom_body.h"

//--------------------------------------------------------------------
// Global Variables
char *tName;
double trans_time;
double waste_time;
int status = LR_PASS;

int i = 1;
int j = 1;
int k = 1;
int maxk = 0;
int randomize=0;
int number=0;
int randomDelete=0;
int maxticket[3];
char* strg[];
char stst[];

#endif // _GLOBALS_H


end_transaction(char *tName, int status){
trans_time=lr_get_transaction_duration(tName);
waste_time=lr_get_transaction_wasted_time(tName);
lr_save_int(status, "TRANSACTION_STATUS");
lr_save_string(tName, "TRANSACTION_NAME");
lr_end_transaction(tName,status);
lr_save_int(trans_time*1000 - waste_time*1000, "RESPONSE_TIME");

web_custom_request("InfluxDB",
"URL=http://localhost:8086/write?db=Lesson8Business",
"Method=POST",
"Body=business_metrics,name={TRANSACTION_NAME},status={TRANSACTION_STATUS} response_time={RESPONSE_TIME}",
LAST); }