OneTicketDel()
{
	tName = "09.OpenPage_Itinerary_OneTicketDel";
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
	
	tName = "10.Delete_One_Ticket";
	lr_start_transaction(tName);

	/* Del 1 Ticket */
	
	web_submit_data("itinerary.pl", 
		"Action={Host}/cgi-bin/itinerary.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer={Host}/cgi-bin/itinerary.pl", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=flightID", "Value={FlightID_1}", ENDITEM,
		"Name=1", "Value=on", ENDITEM,
		"Name=.cgifields", "Value=1", ENDITEM,
		"Name=removeFlights.x", "Value=69", ENDITEM,
		"Name=removeFlights.y", "Value=8", ENDITEM,
		LAST);
	
	end_transaction(tName, status);
	
	return 0;
}
