/**********************************************************************
 *  readme.txt template                                                   
 *  Kronos PS7a startup
 **********************************************************************/

Name: Shivam Patel


Hours to complete assignment (optional): 3


/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/

Yes I completed the whole assignment. I know it works because I looked
for the number of startups in some of the files to see how many there
were and if my cod reported all of them.

/**********************************************************************
 *  Copy here all regex's you created for parsing the file, 
 *  and explain individually what each ones does.
 **********************************************************************/
boost::regex beginBoot(
        "([0-9]{4})-([0-9]{2})-([0-9]{2}) "
        "([0-9]{2}):([0-9]{2}):([0-9]{2}): "
        "\\(log.c.166\\) server started");
This regex looks for the startup connection and looks for the time and
and date of the startup.

boost::regex endBoot(
        "([0-9]{4})-([0-9]{2})-([0-9]{2}) "
        "([0-9]{2}):([0-9]{2}):([0-9]{2}).([0-9]{3}):"
        "INFO:oejs.AbstractConnector:Started SelectChannelConnector@0.0.0.0:9080");
This regex looks for the time and date of each matching boot completion.


/**********************************************************************
 *  Describe your overall approach for solving the problem.
 *  100-200 words.
 **********************************************************************/
Two regex's were declared in order to look for the matching startup and
boot completion. The code looks for the boot startup and makes the boot
variable true if one is found. If another startup is found it is set to
false which means its an incomplete boot and that is outputted to the
report file. If there is a matching end boot, then the elapsed time is
calculated between the last startup and end boot. The info is outputted
to the report file.

/**********************************************************************
 *  List whatever help (if any) you received from lab TAs,
 *  classmates, or anyone else.
 **********************************************************************/
Stack OverFlow, Boost Library


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
None


/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
None
