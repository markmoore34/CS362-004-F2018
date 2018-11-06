/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

import junit.framework.TestCase;

/**
 * Performs Validation Test for url validations.
 *
 * @version $Revision: 1739358 $
 */
public class UrlValidatorTest extends TestCase {
	
	private final boolean printStatus = false;
	private final boolean printIndex = false;//print index that indicates current scheme,host,port,path, query test we're using.
	
	public UrlValidatorTest(String testName) {
		super(testName);
	}
	
	@Override				//WHAT IS THIS???
	protected void setUp() {
		for (int index = 0; index < testPartsIndex.length - 1; index++) {
			testPartsIndex[index] = 0;
		}
	}
	
	public void testIsValid() {//accepts no parameters, but calls the other testIsValid which accepts 2 parameters.
		testIsValid(testUrlParts, UrlValidator.ALLOW_ALL_SCHEMES);//testUrlParts if the array of al the arrays of parts
		setUp();
		//        int options =
		//            UrlValidator.ALLOW_2_SLASHES
		//                + UrlValidator.ALLOW_ALL_SCHEMES
		//                + UrlValidator.NO_FRAGMENTS;
		//
		//        testIsValid(testUrlPartsOptions, options);
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
		
	}
	
	/**
	 * Create set of tests by taking the testUrlXXX arrays and
	 * running through all possible permutations of their combinations.
	 *
	 * @param testObjects Used to create a url.
	 */
	public void testIsValid(Object[] testObjects, long allowAllSchemes)//called by testIsValid which has no params. testObjects and testPartsIndex coincide. testPartsIndex gives the # of the object within testObjects[] to grab.
	{
		UrlValidator urlVal = new UrlValidator(null, null, allowAllSchemes);//create Urlvalidator object
																			//UrlValidator urlVal = new UrlValidator(null, allowAllSchemes);
		assertTrue(urlVal.isValid("http://www.google.com"));//check that this url is valid
		assertTrue(urlVal.isValid("http://www.google.com/"));
		int statusPerLine = 60;//60 status's per inquiry?
		int printed = 0;
		if (printIndex)  {//this is set as false on line 28 but isn't changed anywhere else?
			statusPerLine = 6;
		}
		do {
			StringBuilder testBuffer = new StringBuilder();//this must be from the "junit" import on line 18. builds the string?
			boolean expected = true;
			for (int testPartsIndexIndex = 0; testPartsIndexIndex < testPartsIndex.length; ++testPartsIndexIndex) {//test parts index is a 5 element array that holds the elementst to grab from the 5 URL parts arrays. testPartsIndex.length = 5(line 276)
				int index = testPartsIndex[testPartsIndexIndex]; //put that # into index;
				ResultPair[] part = (ResultPair[]) testObjects[testPartsIndexIndex];//grab the obj in that index of the testObjects[] parameter. it's typdef'd
				testBuffer.append(part[index].item);//append that url part into the "testBuffer" string
				expected &= part[index].valid;/**a &= b; is equivalent to a = a & b; In some usages, the type-casting makes
											   a difference to the result, but in this one b has to be boolean and the
											   type-cast does nothing.
											   "valid" is the true or false. If the part is not valid,
											   expected is set to false.
											   **/
			}
			String url = testBuffer.toString();//convert the "testbuffer" to a string called "url"
			boolean result = urlVal.isValid(url);//check that if the url is valid
			if(result == true)
				System.out.println(url);//if it's a good url, print it.
			assertEquals(url, expected, result);//check that the 3? things are boolean equal?
			if (printStatus) {//this is set as false on line 27 but isn't changed anywhere else?
				if (printIndex) {//this is set as false on line 28 but isn't changed anywhere else?
					System.out.print(testPartsIndextoString());//convert the index# to a string and print it.
				} else {
					if (result == expected) {//another check of result and expected.
						System.out.print('.');//if the result == true(expected from line 96)
					} else {
						System.out.print('X');
					}
				}
				printed++;//another valid url has been printed.
				if (printed == statusPerLine) {//status per line is 60(set on line 89)
					System.out.println();//prints to the console?
					printed = 0;//reset to 0 and start again.
				}
			}
		} while (incrementTestPartsIndex(testPartsIndex, testObjects));//there are still options to try.
		if (printStatus) {
			System.out.println();
		}
	}//end of testIsValid
	
	public void testValidator202() {
		String[] schemes = {"http","https"};
		UrlValidator urlValidator = new UrlValidator(schemes, UrlValidator.NO_FRAGMENTS);
		urlValidator.isValid("http://www.logoworks.comwww.logoworks.comwww.logoworks.comwww.logoworks.comwww.logoworks.comwww.logoworks.comwww.logoworks.comwww.logoworks.comwww.logoworks.comwww.logoworks.comwww.logoworks.comwww.logoworks.comwww.logoworks.comwww.logoworks.comwww.logoworks.comwww.logoworks.comwww.logoworks.comwww.logoworks.comwww.logoworks.comwww.logoworks.comwww.logoworks.comwww.logoworks.comwww.logoworks.comwww.logoworks.comwww.logoworks.comwww.logoworks.comwww.logoworks.comwww.logoworks.comwww.logoworks.comwww.log");
	}
	
	public void testValidator204() {
		String[] schemes = {"http","https"};
		UrlValidator urlValidator = new UrlValidator(schemes);
		assertTrue(urlValidator.isValid("http://tech.yahoo.com/rc/desktops/102;_ylt=Ao8yevQHlZ4On0O3ZJGXLEQFLZA5"));
	}
	
	static boolean incrementTestPartsIndex(int[] testPartsIndex, Object[] testParts) {
		boolean carry = true;  //add 1 to lowest order part.
		boolean maxIndex = true;
		for (int testPartsIndexIndex = testPartsIndex.length - 1; testPartsIndexIndex >= 0; --testPartsIndexIndex) {
			int index = testPartsIndex[testPartsIndexIndex];//goes over each element in testPartsIndex to increment it, starting with the last one(4).
			ResultPair[] part = (ResultPair[]) testParts[testPartsIndexIndex];//get the part obj and put into part
			if (carry) {
				if (index < part.length - 1) {//if index is less than the length of the obj part[] from obj testParts[]
					index++;//increment index
					testPartsIndex[testPartsIndexIndex] = index;//make the index # one more
					carry = false;
				} else {
					testPartsIndex[testPartsIndexIndex] = 0;
					carry = true;
				}
			}
			maxIndex &= (index == (part.length - 1));//both must be true/false.
		}
		return (!maxIndex);
	}
	
	private String testPartsIndextoString() {
		StringBuilder carryMsg = new StringBuilder("{");
		for (int testPartsIndexIndex = 0; testPartsIndexIndex < testPartsIndex.length; ++testPartsIndexIndex) {
			carryMsg.append(testPartsIndex[testPartsIndexIndex]);
			if (testPartsIndexIndex < testPartsIndex.length - 1) {
				carryMsg.append(',');
			} else {
				carryMsg.append('}');
			}
		}
		return carryMsg.toString();
		
	}
	
	public void testValidateUrl() {
		assertTrue(true);
	}
	
	/**
	 * Only used to debug the unit tests.
	 * @param argv
	 */
	public static void main(String[] argv) {
		
		UrlValidatorTest fct = new UrlValidatorTest("url test");
		fct.setUp();
		fct.testIsValid();
		fct.testIsValidScheme();
	}
	//-------------------- Test data for creating a composite URL
	/**
	 * The data given below approximates the 4 parts of a URL
	 * <scheme>://<authority><path>?<query> except that the port number
	 * is broken out of authority to increase the number of permutations.
	 * A complete URL is composed of a scheme+authority+port+path+query,
	 * all of which must be individually valid for the entire URL to be considered
	 * valid.
	 */
	ResultPair[] testUrlScheme = {new ResultPair("http://", true),
	new ResultPair("ftp://", true),
	new ResultPair("h3t://", true),
	new ResultPair("3ht://", false),
	new ResultPair("http:/", false),
	new ResultPair("http:", false),
	new ResultPair("http/", false),
	new ResultPair("://", false),
	new ResultPair("", true)};
	
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
	};
	ResultPair[] testUrlPort = {new ResultPair(":80", true),
	new ResultPair(":65535", true),
	new ResultPair(":0", true),
	new ResultPair("", true),
	new ResultPair(":-1", false),
	new ResultPair(":65636",false),
	new ResultPair(":65a", false)
	};
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
	};
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
	};
	
	Object[] testUrlParts = {testUrlScheme, testUrlAuthority, testUrlPort, testPath, testUrlQuery};//an array of arrays(which start on line 203
	Object[] testUrlPartsOptions = {testUrlScheme, testUrlAuthority, testUrlPort, testUrlPathOptions, testUrlQuery};
	int[] testPartsIndex = {0, 0, 0, 0, 0};
	
	//---------------- Test data for individual url parts ----------------
	ResultPair[] testScheme = {new ResultPair("http", true),
	new ResultPair("ftp", false),
	new ResultPair("httpd", false),
	new ResultPair("telnet", false)};
	
	
}
