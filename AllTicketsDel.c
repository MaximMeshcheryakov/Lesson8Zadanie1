AllTicketsDel()
{
	
	tName = "07.OpenPage_Itinerary_AllTicketDel";
	lr_start_transaction(tName);
	
	web_reg_save_param_ex(
    	"ParamName=FlightID", 
    	"LB/IC=name=\"flightID\" value=\"",
    	"RB/IC=\"  ",
    	"Ordinal=all",
	LAST);
	
	/* Itinerary */

	web_url("Itinerary Button", 
		"URL={Host}/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={Host}/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);
	
	end_transaction(tName, status);
	
	tName = "08.Delete_All_Tickets";
	lr_start_transaction(tName);
	
	/* Del All Ticket */

	web_submit_data("itinerary.pl", 
		"Action=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=flightID", "Value={FlightID_1}", ENDITEM, 
		"Name=.cgifields", "Value=1", ENDITEM, 
		"Name=.cgifields", "Value=2", ENDITEM, 
		"Name=removeAllFlights.x", "Value=43", ENDITEM, 
		"Name=removeAllFlights.y", "Value=14", ENDITEM, 
		LAST);
	
	end_transaction(tName, status);
	
	return 0;
}
