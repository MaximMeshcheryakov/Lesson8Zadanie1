vuser_end()
{
	tName = "11.Log_out";
	lr_start_transaction(tName);
	
	/* Sign Off */

	web_url("SignOff Button", 
		"URL={Host}/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={Host}/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);
	
	end_transaction(tName, status);
	
	return 0;
}
