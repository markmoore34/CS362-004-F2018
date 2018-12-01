

import junit.framework.TestCase;
import java.util.Random;
//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!


public class UrlValidatorTest extends TestCase {
	   //private final boolean printStatus = false;

	/**   @Override				//WHAT IS THIS???
	   protected void setUp() {
	      for (int index = 0; index < testPartsIndex.length - 1; index++) {
	         testPartsIndex[index] = 0;
	      }
	   }
	   
	   public void testIsValidScheme() {
		      if (printStatus) {
		         System.out.print("\n testIsValidScheme() ");
		      }
		      String[] schemes = {"http", "gopher"};
		      //UrlValidator urlVal = new UrlValidator(schemes,false,false,false);
		      UrlValidator urlVal = new UrlValidator(schemes, 0);
		      for (int sIndex = 0; sIndex < testScheme.length; sIndex++) {
		         ResultPair testPair = testScheme[sIndex];
		         boolean result = urlVal.isValidScheme(testPair.item);
		         assertEquals(testPair.item, testPair.valid, result);
		         if (printStatus) {
		            if (result == testPair.valid) {
		               System.out.print('.');
		            } else {
		               System.out.print('X');
		            }
		         }
		      }
		      if (printStatus) {
		         System.out.println();
		      }

		   }**/

   public UrlValidatorTest(String testName) {
      super(testName);
   }

   public void testManualTest()
   {
//You can use this function to implement your manual testing	   
	   
   }
   
   public void testYourFirstPartition()
   {
	 //You can use this function to implement your First Partition testing	   

   }
   
   public void testYourSecondPartition(){
		 //You can use this function to implement your Second Partition testing	   

   }
   //You need to create more test cases for your Partitions if you need to 
   
   public void testIsValid()//Object[] testUrlPart, long allowAllSchemes)		//NOT totally sure this is correct
   {	
	   Random rand = new Random();//make a random object
	   int n = -1; 
	   int o = -1;
	   int p = -1;
	   int q = -1;
	   int r = -1;
	   //UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   //UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_LOCAL_URLS);
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.NO_FRAGMENTS);
	   //UrlValidator urlVal = new UrlValidator();
	   
	   //get random # within the range of the sub array
	   boolean preValid = true;//to compare the .valid of each string appended. Change to false if .valid is false.
	   for (int i = 0; i < 10; ++i) {
    	  //System.out.printf("\tSTARTING LOOP\n");
    	  
    	  StringBuilder testBuffer = new StringBuilder();//this must be from the "junit" import on line 18. builds the string?
    	  
    	  /**if (urlVal.isValid("ftp://foo.bar.com/")) {
    	        System.out.println("url is valid");
    	  } 
    	  else {
    	        System.out.println("url is invalid");
    	  }**/
          n = rand.nextInt(8);//8 is the maximum and the 1 is the minimum.
          testBuffer.append(testUrlScheme[n].item);
          if(!testUrlScheme[n].valid)  		{preValid = false;}  
          //System.out.printf("\tScheme PASSED");

          o = rand.nextInt(17);//17 is the maximum and the 0 is the minimum.
          testBuffer.append(testUrlAuthority[o].item);
          if(!testUrlAuthority[o].valid)	{preValid = false;}  
          //System.out.printf("\tAuthority PASSED");
          
          p = rand.nextInt(6);//6 is the maximum and the 0 is the minimum.
          testBuffer.append(testUrlPort[p].item);
          if(!testUrlPort[p].valid)  		{preValid = false;}  
          //System.out.printf("\tPort PASSED");

          q = rand.nextInt(9);//9 is the maximum and the 0 is the minimum.
          testBuffer.append(testPath[q].item);
          if(!testPath[q].valid) 			{preValid = false;}   
          //System.out.printf("\tPath PASSED");

          r = rand.nextInt(2);//2 is the maximum and the 0 is the minimum.
          testBuffer.append(testUrlQuery[r].item);
          if(!testUrlQuery[r].valid)  		{preValid = false;}  
          //System.out.printf("\tQuery PASSED\n");
         
          //System.out.printf("Hello, World \n\t%s\n", testBuffer); 
          String url = testBuffer.toString();//convert the "testbuffer" to a string called "url"
          System.out.printf("\tSENDING " + url +" TO ISVALID()\n");
          boolean postVal = urlVal.isValid(url);
          System.out.printf("\tISVALID() RETURNED " + postVal + " = postVal\n");
          
          System.out.printf(preValid + "\treturned  " + postVal + "\turl=\t" + testBuffer + "\n"); 
      	}//end of URL building 4-loop
      
      	boolean trueURL = urlVal.isValid("http://www.google.com");
      	System.out.printf(trueURL + "   http://www.google.com...this should be true...\n");
      	trueURL = urlVal.isValid("http://www.amazon.com");
      	System.out.printf(trueURL + "   http://www.amazon.com...this should be true...\n");   	
   }//end of testIsValid
   
  /** public static void main(String[] argv) {

	  UrlValidatorTest fct = new UrlValidatorTest("url test");
      fct.setUp();
      fct.testIsValid();
      fct.testIsValidScheme();
   }  **/ 
   
   ResultPair[] testUrlScheme = {new ResultPair("http://", true),
           new ResultPair("ftp://", true),
           new ResultPair("h3t://", true),
           new ResultPair("3ht://", false),
           new ResultPair("http:/", false),
           new ResultPair("http:", false),
           new ResultPair("http/", false),
           new ResultPair("://", false),
           new ResultPair("", true)};//8
	
	ResultPair[] testUrlAuthority = {new ResultPair("www.google.com", true),
	              new ResultPair("go.com", true),
	              new ResultPair("go.au", true),
	              new ResultPair("0.0.0.0", true),
	              new ResultPair("255.255.255.255", true),
	              new ResultPair("256.256.256.256", false),
	              new ResultPair("255.com", true),
	              new ResultPair("1.2.3.4.5", false),
	              new ResultPair("1.2.3.4.", false),
	              new ResultPair("1.2.3", false),
	              new ResultPair(".1.2.3.4", false),
	              new ResultPair("go.a", false),
	             new ResultPair("go.a1a", false),
	              new ResultPair("go.1aa", false),
	              new ResultPair("aaa.", false),
	              new ResultPair(".aaa", false),
	              new ResultPair("aaa", false),
	              new ResultPair("", false)
	};//17
	ResultPair[] testUrlPort = {new ResultPair(":80", true),
	         new ResultPair(":65535", true),
	         new ResultPair(":0", true),
	         new ResultPair("", true),
	         new ResultPair(":-1", false),
	        new ResultPair(":65636",false),
	         new ResultPair(":65a", false)
	};//6
	ResultPair[] testPath = {new ResultPair("/test1", true),
	      new ResultPair("/t123", true),
	      new ResultPair("/$23", true),
	      new ResultPair("/..", false),
	      new ResultPair("/../", false),
	      new ResultPair("/test1/", true),
	      new ResultPair("", true),
	      new ResultPair("/test1/file", true),
	      new ResultPair("/..//file", false),
	      new ResultPair("/test1//file", false)
	};//9
	//Test allow2slash, noFragment
	ResultPair[] testUrlPathOptions = {new ResultPair("/test1", true),
	                new ResultPair("/t123", true),
	                new ResultPair("/$23", true),
	                new ResultPair("/..", false),
	                new ResultPair("/../", false),
	                new ResultPair("/test1/", true),
	                new ResultPair("/#", false),
	                new ResultPair("", true),
	                new ResultPair("/test1/file", true),
	                new ResultPair("/t123/file", true),
	                new ResultPair("/$23/file", true),
	                new ResultPair("/../file", false),
	                new ResultPair("/..//file", false),
	                new ResultPair("/test1//file", true),
	                new ResultPair("/#/file", false)
	};
	
	ResultPair[] testUrlQuery = {new ResultPair("?action=view", true),
	          new ResultPair("?action=edit&mode=up", true),
	          new ResultPair("", true)
	};//2
	
	//use array parts from testUrlParts
	Object[] testUrlParts = {testUrlScheme, testUrlAuthority, testUrlPort, testPath, testUrlQuery};//an array of arrays(which start on line 203
	//Object[] testUrlPartsOptions = {testUrlScheme, testUrlAuthority, testUrlPort, testUrlPathOptions, testUrlQuery};
	//int[] testPartsIndex = {0, 0, 0, 0, 0};
	
	//---------------- Test data for individual url parts ----------------
	ResultPair[] testScheme = {new ResultPair("http", true),
	        new ResultPair("ftp", false),
	        new ResultPair("httpd", false),
	        new ResultPair("telnet", false)};
	

}
