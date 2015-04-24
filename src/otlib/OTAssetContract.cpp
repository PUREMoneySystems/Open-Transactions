/************************************************************
 *    
 *  OTAssetContract.cpp
 *  
 */

/************************************************************
 -----BEGIN PGP SIGNED MESSAGE-----
 Hash: SHA1
 
 *                 OPEN TRANSACTIONS
 *
 *       Financial Cryptography and Digital Cash
 *       Library, Protocol, API, Server, CLI, GUI
 *
 *       -- Anonymous Numbered Accounts.
 *       -- Untraceable Digital Cash.
 *       -- Triple-Signed Receipts.
 *       -- Cheques, Vouchers, Transfers, Inboxes.
 *       -- Basket Currencies, Markets, Payment Plans.
 *       -- Signed, XML, Ricardian-style Contracts.
 *       -- Scripted smart contracts.
 *
 *  Copyright (C) 2010-2013 by "Fellow Traveler" (A pseudonym)
 *
 *  EMAIL:
 *  FellowTraveler@rayservers.net
 *
 *  BITCOIN:  1NtTPVVjDsUfDWybS4BwvHpG2pdS9RnYyQ
 *
 *  KEY FINGERPRINT (PGP Key in license file):
 *  9DD5 90EB 9292 4B48 0484  7910 0308 00ED F951 BB8E
 *
 *  OFFICIAL PROJECT WIKI(s):
 *  https://github.com/FellowTraveler/Moneychanger
 *  https://github.com/FellowTraveler/Open-Transactions/wiki
 *
 *  WEBSITE:
 *  http://www.OpenTransactions.org/
 *
 *  Components and licensing:
 *   -- Moneychanger..A Java client GUI.....LICENSE:.....GPLv3
 *   -- otlib.........A class library.......LICENSE:...LAGPLv3
 *   -- otapi.........A client API..........LICENSE:...LAGPLv3
 *   -- opentxs/ot....Command-line client...LICENSE:...LAGPLv3
 *   -- otserver......Server Application....LICENSE:....AGPLv3
 *  Github.com/FellowTraveler/Open-Transactions/wiki/Components
 *
 *  All of the above OT components were designed and written by
 *  Fellow Traveler, with the exception of Moneychanger, which
 *  was contracted out to Vicky C (bitcointrader4@gmail.com).
 *  The open-source community has since actively contributed.
 *
 *  -----------------------------------------------------
 *
 *   LICENSE:
 *   This program is free software: you can redistribute it
 *   and/or modify it under the terms of the GNU Affero
 *   General Public License as published by the Free Software
 *   Foundation, either version 3 of the License, or (at your
 *   option) any later version.
 *
 *   ADDITIONAL PERMISSION under the GNU Affero GPL version 3
 *   section 7: (This paragraph applies only to the LAGPLv3
 *   components listed above.) If you modify this Program, or
 *   any covered work, by linking or combining it with other
 *   code, such other code is not for that reason alone subject
 *   to any of the requirements of the GNU Affero GPL version 3.
 *   (==> This means if you are only using the OT API, then you
 *   don't have to open-source your code--only your changes to
 *   Open-Transactions itself must be open source. Similar to
 *   LGPLv3, except it applies to software-as-a-service, not
 *   just to distributing binaries.)
 *
 *   Extra WAIVER for OpenSSL, Lucre, and all other libraries
 *   used by Open Transactions: This program is released under
 *   the AGPL with the additional exemption that compiling,
 *   linking, and/or using OpenSSL is allowed. The same is true
 *   for any other open source libraries included in this
 *   project: complete waiver from the AGPL is hereby granted to
 *   compile, link, and/or use them with Open-Transactions,
 *   according to their own terms, as long as the rest of the
 *   Open-Transactions terms remain respected, with regard to
 *   the Open-Transactions code itself.
 *
 *   Lucre License:
 *   This code is also "dual-license", meaning that Ben Lau-
 *   rie's license must also be included and respected, since
 *   the code for Lucre is also included with Open Transactions.
 *   See Open-Transactions/src/otlib/lucre/LUCRE_LICENSE.txt
 *   The Laurie requirements are light, but if there is any
 *   problem with his license, simply remove the Lucre code.
 *   Although there are no other blind token algorithms in Open
 *   Transactions (yet. credlib is coming), the other functions
 *   will continue to operate.
 *   See Lucre on Github:  https://github.com/benlaurie/lucre
 *   -----------------------------------------------------
 *   You should have received a copy of the GNU Affero General
 *   Public License along with this program.  If not, see:
 *   http://www.gnu.org/licenses/
 *
 *   If you would like to use this software outside of the free
 *   software license, please contact FellowTraveler.
 *   (Unfortunately many will run anonymously and untraceably,
 *   so who could really stop them?)
 *
 *   DISCLAIMER:
 *   This program is distributed in the hope that it will be
 *   useful, but WITHOUT ANY WARRANTY; without even the implied
 *   warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *   PURPOSE.  See the GNU Affero General Public License for
 *   more details.
 
 -----BEGIN PGP SIGNATURE-----
 Version: GnuPG v1.4.9 (Darwin)
 
 iQIcBAEBAgAGBQJRSsfJAAoJEAMIAO35UbuOQT8P/RJbka8etf7wbxdHQNAY+2cC
 vDf8J3X8VI+pwMqv6wgTVy17venMZJa4I4ikXD/MRyWV1XbTG0mBXk/7AZk7Rexk
 KTvL/U1kWiez6+8XXLye+k2JNM6v7eej8xMrqEcO0ZArh/DsLoIn1y8p8qjBI7+m
 aE7lhstDiD0z8mwRRLKFLN2IH5rAFaZZUvj5ERJaoYUKdn4c+RcQVei2YOl4T0FU
 LWND3YLoH8naqJXkaOKEN4UfJINCwxhe5Ke9wyfLWLUO7NamRkWD2T7CJ0xocnD1
 sjAzlVGNgaFDRflfIF4QhBx1Ddl6wwhJfw+d08bjqblSq8aXDkmFA7HeunSFKkdn
 oIEOEgyj+veuOMRJC5pnBJ9vV+7qRdDKQWaCKotynt4sWJDGQ9kWGWm74SsNaduN
 TPMyr9kNmGsfR69Q2Zq/FLcLX/j8ESxU+HYUB4vaARw2xEOu2xwDDv6jt0j3Vqsg
 x7rWv4S/Eh18FDNDkVRChiNoOIilLYLL6c38uMf1pnItBuxP3uhgY6COm59kVaRh
 nyGTYCDYD2TK+fI9o89F1297uDCwEJ62U0Q7iTDp5QuXCoxkPfv8/kX6lS6T3y9G
 M9mqIoLbIQ1EDntFv7/t6fUTS2+46uCrdZWbQ5RjYXdrzjij02nDmJAm2BngnZvd
 kamH0Y/n11lCvo1oQxM+
 =uSzz
 -----END PGP SIGNATURE-----
 **************************************************************/

#define _USE_MATH_DEFINES
#include <cmath>

#include "stdafx.hpp"

#include "OTAssetContract.hpp"

#include "OTAccount.hpp"
#include "OTASCIIArmor.hpp"
#include "OTAcctFunctor.hpp"
#include "OTAmount.hpp"
#include "OTBasket.hpp"
#include "OTFolders.hpp"
#include "OTLog.hpp"
#include "OTStorage.hpp"

#include "OTBylaw.hpp"
#include "OTClause.hpp"

#include "irrxml/irrXML.hpp"

#include <fstream>

#ifdef OT_USE_SCRIPT_CHAI
#	include "OTScriptChai.hpp"
#	include <chaiscript/chaiscript.hpp>
#	ifdef OT_USE_CHAI_STDLIB
#	    include <chaiscript/chaiscript_stdlib.hpp>
#	endif
#endif


using namespace irr;
using namespace io;


// static
bool OTAssetContract::ParseFormatted(int64_t & lResult,
                                     const std::string & str_input,
                                     int32_t nFactor/*=100*/,
                                     int32_t nPower/*=2*/,
                                     const char * szSeparator/*=","*/,
                                     const char * szDecimalPoint/*="."*/)
{
    OT_ASSERT(NULL != szSeparator);
    OT_ASSERT(NULL != szDecimalPoint);
    // ----------------------
    lResult = 0;
    // ----------------------
    char theSeparator    = szSeparator[0];
    char theDecimalPoint = szDecimalPoint[0];
    // ----------------------
    int64_t lDollars = 0;
    int64_t lCents   = 0;
    int64_t lOutput  = 0;
    int64_t lSign    = 1;
    // ----------------------
    bool bHasEnteredDollars = false;
    bool bHasEnteredCents   = false;
    // ----------------------
    int32_t  nDigitsCollectedBeforeDot = 0;
    int32_t  nDigitsCollectedAfterDot  = 0;
    // ----------------------
	// BUG: &mp isn't used.
    //const std::moneypunct<char, false> &mp = std::use_facet< std::moneypunct<char, false> >(std::locale ()); 
    // ----------------------
    std::deque<int64_t> deque_cents;
    // ----------------------
    for (uint32_t uIndex = 0; uIndex < str_input.length(); ++uIndex)
    {
        char theChar = str_input[uIndex];
        // -------------------------------
        if (iscntrl(theChar)) // Break at any newline or other control character.
            break;
        // -------------------------------
        if (0 == isdigit(theChar)) // if it's not a numerical digit.
        {
            if (theSeparator == theChar)
                continue;
            // -------------------------------
            if (theDecimalPoint == theChar)
            {
                if (bHasEnteredCents)
                {
                    // There shouldn't be ANOTHER decimal point if we are already in the cents.
                    // Therefore, we're done here. Break.
                    //
                    break;
                }
                // -------------------------------
                // If we HAVEN'T entered the cents yet, then this decimal point marks the spot where we DO.
                //
                bHasEnteredDollars = true;
                bHasEnteredCents   = true;
                continue;
            } // theChar is the decimal point
            // -------------------------------
            // Once a negative sign appears, it's negative, period.
            // If you put two or three negative signs in a row, it's STILL negative.
            //
//          std::string str_negative(1, theChar);
//          if (0 == str_negative.compare(mp.negative_sign()))
            
            if ('-' == theChar)
            {
                lSign = -1;
                continue;
            }
//          std::cout << "FYI, negative sign: " << mp.negative_sign() << " str_negative: " << str_negative << " lSign: " << lSign << std::endl;
            // -------------------------------
            // Okay, by this point, we know it's not numerical, and it's not a separator or decimal point, or
            // sign.
            // We allow letters and symbols BEFORE the numbers start, but not AFTER (that would terminate the
            // number.) Therefore we need to see if the dollars or cents have started yet. If they have, then
            // this is the end, and we break. Otherwise if they haven't, then we're still at the beginning, so
            // we continue.
            //
            if (bHasEnteredDollars || bHasEnteredCents)
                break;
            else
                continue;
        } // not numerical
        // -------------------------------
        // By this point, we KNOW that it's a numeric digit.
        // Are we collecting cents yet? How about dollars?
        // Also, if nPower is 2, then we only collect 2 digits
        // after the decimal point. If we've already collected
        // those, then we need to break.
        //
        if (bHasEnteredCents)
        {
            ++nDigitsCollectedAfterDot;
            
            // If "cents" occupy 2 digits after the decimal point,
            // and we are now on the THIRD digit -- then we're done.
            if (nDigitsCollectedAfterDot > nPower)
                break;
            // -----------------------------------
            // Okay, we're in the cents, so let's add this digit...
            //
            deque_cents.push_back(static_cast<int64_t>(theChar - '0'));
            // ----------------
            continue;
        }
        // -------------------------------
        // Okay, it's a digit, and we haven't started processing cents yet.
        // How about dollars?
        //
        if (!bHasEnteredDollars)
            bHasEnteredDollars = true;
        // -------------------------------
        ++nDigitsCollectedBeforeDot;
        // -------------------------------
        // Let's add this digit...
        //
        lDollars *= 10; // Multiply existing dollars by 10, and then add the new digit.
        lDollars += static_cast<int64_t>(theChar - '0');
    } // for
    // -------------------------------
    // Time to put it all together...
    //
    lOutput += lDollars;
    lOutput *= static_cast<int64_t>(nFactor); // 1 dollar becomes 100 cents.
    // -------------------------------
    int32_t nTempPower = nPower;
    
    while (nTempPower > 0)
    {
        --nTempPower;
        
        if (deque_cents.size() > 0)
        {
            lCents += deque_cents.front();
            deque_cents.pop_front();
        }
        
        lCents *= 10;
    }
    lCents /= 10; // There won't be any rounding errors here, since the last thing we did in the loop was multiply by 10.
    // -------------------------------
    lOutput += lCents;
    // -------------------------------
    lResult = (lOutput * lSign);
    // -------------------------------
    return true;
}


//static
std::string OTAssetContract::formatLongAmount(int64_t & lOriginalValue, int32_t nFactor/*=100*/, int32_t nPower/*=2*/, const char * szSymbol/*=""*/,
                                              const char * szSeparator/*=","*/, const char * szDecimalPoint/*="."*/)
{
    std::stringstream sss;
    OTString strRemainder;
    // --------------------------------------------------
    // If the original value is 0, we still want to format the
    // string properly for a 0 value. (And then return.)
    //
    if (0 == lOriginalValue)
    {
        sss << szSymbol << " "; // Currency symbol
        
        if (!(nFactor < 2))
        {
            sss << szDecimalPoint;
            
            strRemainder.Format("%0*ld", nPower, 0);
        }
        else
            strRemainder.Format("%lld", 0);
        
        sss << strRemainder.Get();
        return sss.str();
    }
    // --------------------------------------------------
    int64_t lAbsoluteValue = (lOriginalValue > 0) ? lOriginalValue : (lOriginalValue * (-1));
    // --------------------------------------------------    
    int64_t lValue     = lAbsoluteValue / nFactor; // For example, if 506 is supposed to be $5.06, then dividing 506 by factor of 100 results in 5 dollars.
    int64_t lRemainder = lAbsoluteValue % nFactor; // For example, if 506 is supposed to be $5.06, then 506 mod 100 results in 6 cents.
    
    if (nFactor < 2) // Basically, if nFactor is 1.
        strRemainder.Set("");
    else
        strRemainder.Format("%0*ld", nPower, lRemainder); // If remainder is 6 (cents) and nPower is 2, strRemainder gets set here to 06.    
    // ------------------------------------------------------
    // Here we add the negative sign, if the value itself is negative.
    //
    if (lOriginalValue < 0)
    {
//        const std::moneypunct<char, false> &mp = std::use_facet< std::moneypunct<char, false> >(std::locale ());
//        sss << mp.negative_sign();
     
        // For some reason the above code isn't working, so I've got the negative sign
        // hardcoded here to '-'.
        //
        sss << "-";
    }
    // ------------------------------------------------------    
    // Here we add the currency symbol.
    //
    sss << szSymbol << " "; // Currency symbol
    // ------------------------------------------------------
    OTString strValue;
    strValue.Format("%lld", lValue);
    // ---------------------------------
    char     cTemp = '\0';
    uint32_t uValueStrLength = strValue.GetLength();
    // ---------------------------------
    // Here we add the main body of the amount, including separators (commas.)
    //
    while (uValueStrLength > 0)
    {
        cTemp = strValue.sgetc();
        
        sss << cTemp;
        
        --uValueStrLength;
        
        if ((uValueStrLength > 0) && (0 == (uValueStrLength % 3)))
            sss << szSeparator;
    }
    // ------------------------------------------------------
    // Here we deal with the decimal point, etc.
    //
    if (!(nFactor < 2))
    {
        sss << szDecimalPoint;
        // -----------------------------
        sss << strRemainder.Get();
    }
    // -----------------------------
    return sss.str();
}


// Convert 912545 to "$9,125.45"
//
// (Assuming a Factor of 100, Decimal Power of 2, Currency Symbol of "$",
//  separator of "," and decimal point of ".")
//
bool OTAssetContract::FormatAmount(const OTAmount & theInput, std::string & str_output) const // Convert 545 to $5.45.
{
    int64_t lValue = static_cast<int64_t>(theInput.GetAmount());
    // --------------------------------------------------------
    int32_t nFactor = atoi(m_strCurrencyFactor.Get()); // default is 100  (100 cents in a dollar)
    if (nFactor < 1)
        nFactor = 1;
    OT_ASSERT(nFactor > 0); // should be 1, 10, 100, etc.
    // --------------------------------------------------------
    int32_t nPower = atoi(m_strCurrencyDecimalPower.Get()); // default is 2. ($5.05 is moved 2 decimal places.)
    if (nPower < 0)
        nPower = 0;
    OT_ASSERT(nPower >= 0); // should be 0, 1, 2, etc.
    // --------------------------------------------------------
    // Lookup separator and decimal point symbols based on locale.
    // --------------------------------------------------------
    // Get a moneypunct facet from the global ("C") locale
    //
    // NOTE: Turns out moneypunct kind of sucks.
    // As a result, for internationalization purposes,
    // these values have to be set here before compilation.
    //
    static OTString strSeparator    (OT_THOUSANDS_SEP);
    static OTString strDecimalPoint (OT_DECIMAL_POINT);
    // --------------------------------------------------------
    
    // NOTE: from web searching, I've determined that locale / moneypunct has
    // internationalization problems. Therefore it looks like if you want to
    // build OT for various languages / regions, you're just going to have to
    // edit stdafx.h and change the OT_THOUSANDS_SEP and OT_DECIMAL_POINT variables.
    //
    // The best improvement I can think on that is to check locale and then use
    // it to choose from our own list of hardcoded values. Todo.
    
//    static bool bFirstTime = true;
//    // --------------------------------------------------------
//    if (bFirstTime)
//    {
//        bFirstTime = false;
//        // TODO: Add ability to customize locale here, if necessary.
//        const std::moneypunct<char, false> &mp = std::use_facet< std::moneypunct<char, false> >(std::locale ()); // <=====
//        strSeparator.   Format("%c", ('\0' == mp.thousands_sep ()) ? ',' : mp.thousands_sep ());
//        strDecimalPoint.Format("%c", ('\0' == mp.decimal_point ()) ? '.' : mp.decimal_point ());
//    }
    // --------------------------------------------------------
    str_output = OTAssetContract::formatLongAmount(lValue, nFactor, nPower, m_strCurrencySymbol.Get(),
                                                   strSeparator.Get(), strDecimalPoint.Get());
    return true;
}


// Convert "$9,125.45" to 912545.
//
// (Assuming a Factor of 100, Decimal Power of 2, separator of "," and decimal point of ".")
//
bool OTAssetContract::StringToAmount(OTAmount & theOutput, const std::string & str_input) const // Convert $5.45 to amount 545.
{
    int64_t lValue = 0;
    // --------------------------------------------------------
    int32_t nFactor = atoi(m_strCurrencyFactor.Get()); // default is 100  (100 cents in a dollar)
    if (nFactor < 1)
        nFactor = 1;
    OT_ASSERT(nFactor > 0); // should be 1, 10, 100, etc.
    // --------------------------------------------------------
    int32_t nPower = atoi(m_strCurrencyDecimalPower.Get()); // default is 2. ($5.05 is moved 2 decimal places.)
    if (nPower < 0)
        nPower = 0;
    OT_ASSERT(nPower >= 0); // should be 0, 1, 2, etc.
    // --------------------------------------------------------
    // Lookup separator and decimal point symbols based on locale.
    // --------------------------------------------------------
    // Get a moneypunct facet from the global ("C") locale
    //
    
    // NOTE: from web searching, I've determined that locale / moneypunct has
    // internationalization problems. Therefore it looks like if you want to
    // build OT for various languages / regions, you're just going to have to
    // edit stdafx.h and change the OT_THOUSANDS_SEP and OT_DECIMAL_POINT variables.
    //
    // The best improvement I can think on that is to check locale and then use
    // it to choose from our own list of hardcoded values. Todo.
    
    static OTString strSeparator    (",");
    static OTString strDecimalPoint (".");
    // --------------------------------------------------------
//    static bool bFirstTime = true;
//    // --------------------------------------------------------
//    if (bFirstTime)
//    {
//        bFirstTime = false;
//        // TODO: Add ability to customize locale here, if necessary.
//        const std::moneypunct<char, false> &mp = std::use_facet< std::moneypunct<char, false> >(std::locale ()); // <=====
//        strSeparator.   Format("%c", ('\0' == mp.thousands_sep ()) ? ',' : mp.thousands_sep ());
//        strDecimalPoint.Format("%c", ('\0' == mp.decimal_point ()) ? '.' : mp.decimal_point ());
//    }
    // --------------------------------------------------------
    bool bSuccess = OTAssetContract::ParseFormatted(lValue, str_input, nFactor, nPower, strSeparator.Get(), strDecimalPoint.Get());

    if (bSuccess)
        theOutput.SetAmount(static_cast<int64_t>(lValue));
    
    return bSuccess;
}


// NOTE: the use of "dollars" and "cents" here is only metaphoric.
// For example, if the currency type was Bitcoin, then "dollars" are actually BTC,
// and "cents" are actually satoshis or mBTC.

// Given input of 545, GetDollarsOnly returns 5
//
int64_t OTAssetContract::GetDollarsOnly(const OTAmount & theInput) const
{
    return 0; // TODO
}


// Given input of 545, GetCentsOnly returns 45.

int64_t OTAssetContract::CentsOnly(const OTAmount & theInput) const
{
    return 0; // TODO
}


OTAssetContract::OTAssetContract(OTString & unsignedXML) : OTContract(), m_bIsCurrency(true), m_bIsShares(false){  
  m_xmlUnsigned.Set(unsignedXML);
  LoadContractXML();
}


OTAssetContract::OTAssetContract() : OTContract(), m_bIsCurrency(true), m_bIsShares(false)
{
	
}


OTAssetContract::OTAssetContract(OTString & name, OTString & foldername, OTString & filename, OTString & strID) 
: OTContract(name, foldername, filename, strID), m_bIsCurrency(true), m_bIsShares(false)
{

}


OTAssetContract::~OTAssetContract() {
	// OTContract::~OTContract is called here automatically, and it calls Release.
	// So I don't need to call it here again when it's already called by the parent.
  
	Release_Script();
}

// Go through the existing list of bylaws at this point, and delete them all.
void OTAssetContract::Release_Script() {
	while (!m_mapBylaws.empty()){
		OTBylaw * pBylaw = m_mapBylaws.begin()->second;
		OT_ASSERT(NULL != pBylaw);

		m_mapBylaws.erase(m_mapBylaws.begin());

		delete pBylaw;
		pBylaw = NULL;
	}
}

void OTAssetContract::Release() {
	Release_Script();

	// If there were any dynamically allocated objects, clean them up here.
	OTContract::Release(); // since I've overridden the base class, I call it now...
}



















bool OTAssetContract::DisplayStatistics(OTString & strContents) const
{
	const OTString strID(m_ID);
	
	strContents.Concatenate(
							" Asset Type:  %s\n"
							" AssetTypeID: %s\n"
							"\n",
							m_strName.Get(),
							strID.Get());
	return true;
}


bool OTAssetContract::SaveContractWallet(OTString & strContents) const
{
	const OTString strID(m_ID);
	
	OTASCIIArmor ascName;
	
	if (m_strName.Exists()) // name is in the clear in memory, and base64 in storage.
	{
		ascName.SetString(m_strName, false); // linebreaks == false
	}
	
	strContents.Concatenate("<assetType name=\"%s\"\n"
							" assetTypeID=\"%s\" />\n\n",
							m_strName.Exists() ? ascName.Get() : "",
							strID.Get());
	
	return true;
}


bool OTAssetContract::SaveContractWallet(std::ofstream & ofs)
{
	OTString strOutput;
	
	if (SaveContractWallet(strOutput))
	{
		ofs << strOutput.Get();
		return true;
	}
	
	return false;
}


/*
bool OTAssetContract::SaveContractWallet(FILE * fl)
{
	OTString strID(m_ID);
	
	fprintf(fl, "<assetType name=\"%s\"\n assetTypeID=\"%s\"\n contract=\"%s\" /> "
			"\n\n", m_strName.Get(), strID.Get(), m_strFilename.Get());	
	
	return true;
}
*/


// currently only "simple" accounts (normal user asset accounts) are added to this list
// Any "special" accounts, such as basket reserve accounts, or voucher reserve accounts,
// or cash reserve accounts, are not included on this list.
//
bool OTAssetContract::ForEachAccountRecord(OTAcctFunctor & theAction)  // Loops through all the accounts for a given asset type, and calls Functor on each.
{
    // Load up account list stringmap
    // if success, iterate through map and trigger theAction.
    // loop
    //    theAction.Trigger(theAcct);
    
    OTString strAssetTypeID, strAcctRecordFile;
    this->GetIdentifier(strAssetTypeID);
    strAcctRecordFile.Format("%s.a", strAssetTypeID.Get());
    // --------------------------------------------------------------
    OTDB::Storable * pStorable = OTDB::QueryObject(OTDB::STORED_OBJ_STRING_MAP, OTFolders::Contract().Get(), strAcctRecordFile.Get());
    OTCleanup<OTDB::Storable> theAngel(pStorable); // It will definitely be cleaned up.
    OTDB::StringMap * pMap = (NULL == pStorable) ? NULL : dynamic_cast<OTDB::StringMap *>(pStorable);
    // --------------------------------------------------------------    
    // There was definitely a StringMap loaded from local storage. 
    // (Even an empty one, possibly.) This is the only block that matters in this function.
    //
    if (NULL != pMap) 
    {
        OTIdentifier * pServerID = theAction.GetServerID();        
        OT_ASSERT_MSG(NULL != pServerID, "Assert: NULL Server ID on functor. (How did you even construct the thing?)");
        // -------------------------------------
        mapOfStrings & theMap = pMap->the_map;
        
        // todo: optimize: will probably have to use a database for this, int64_t term. 
        // (What if there are a million acct IDs in this flat file? Not scaleable.)
        //
        FOR_EACH(mapOfStrings, theMap) 
        {
            const std::string & str_acct_id  = (*it).first;	 // Containing the account ID.
            const std::string & str_asset_id = (*it).second; // Containing the asset type ID. (Just in case someone copied the wrong file here...)
            // --------------------------------
            
            if (false == strAssetTypeID.Compare(str_asset_id.c_str()))
            {
                OTLog::vError("OTAssetContract::ForEachAccountRecord: Error: wrong asset type ID (%s) when expecting: %s\n",
                              str_asset_id.c_str(), strAssetTypeID.Get());
            }
            else
            {
                OTAccount * pAccount = NULL;
                OTCleanup<OTAccount> theAcctAngel;
                
                bool  bAlreadyLoaded = false;
                const OTIdentifier theAccountID(str_acct_id.c_str());
                
                // Before loading it from local storage, let's first make sure it's not already loaded.
                // (theAction functor has a list of 'already loaded' accounts, just in case.)
                //
                mapOfAccounts * pLoadedAccounts = theAction.GetLoadedAccts();
                
                if (NULL != pLoadedAccounts) // there are some accounts already loaded, 
                {                            // let's see if the one we're looking for is there...
                    mapOfAccounts::iterator found_it = pLoadedAccounts->find(str_acct_id);
                    
                    if (pLoadedAccounts->end() != found_it) // FOUND IT.
                    {
                        bAlreadyLoaded = true;
                        pAccount = (*found_it).second;
                        OT_ASSERT(NULL != pAccount);
                        
                        if (theAccountID != pAccount->GetPurportedAccountID())
                        {
                            OTLog::Error("Error: the actual account didn't have the ID that the std::map SAID it had! (Should never happen.)\n");
                            bAlreadyLoaded = false;
                            pAccount       = NULL;
                        }
                    }
                }
                // ------------------------------------------------
                // I guess it wasn't already loaded...
                // Let's try to load it.
                //
                if (NULL == pAccount)
                {
                    pAccount = OTAccount::LoadExistingAccount(theAccountID, *pServerID);
                    theAcctAngel.SetCleanupTargetPointer(pAccount);
                }
                // --------------------------------            
                const bool bSuccessLoadingAccount = ((pAccount != NULL) ? true:false );
                if (bSuccessLoadingAccount)
                {
                    const bool bTriggerSuccess = theAction.Trigger(*pAccount);
					if (!bTriggerSuccess) OTLog::vError("%s: Error: Trigger Failed.", __FUNCTION__);
                }   
                else
                {
                    OTLog::vError("%s: Error: Failed Loading Account!", __FUNCTION__);
                }
                // --------------------------------            
            }
        } // FOR_EACH
        
        return true;
    } // if pMap != NULL
    // ----------------------------------------------------------------
    else // nothing was loaded up from local storage. No String Map. It was NULL.
    {
        // Therefore I couldn't possibly loop through "EachAccountRecord", 
        // if there ARE NO account records... right?
        //
        return true; // 
    }
}


bool OTAssetContract::AddAccountRecord(const OTAccount & theAccount) // adds the account to the list. (When account is created.)
{
    //  Load up account list StringMap. Create it if doesn't already exist.
    //  See if account is already there in the map. Add it otherwise.
    //  Save the StringMap back again. (The account records list for a given asset type.)
    
    const char * szFunc = "OTAssetContract::AddAccountRecord";
    
    if (theAccount.GetAssetTypeID() != m_ID)
    {
        OTLog::vError("%s: Error: theAccount doesn't have the same asset type ID as *this does.\n",
                      szFunc);
        return false;
    }
    // --------------------------------------------------------------
    const OTIdentifier theAcctID(theAccount);
    const OTString     strAcctID(theAcctID);
    // --------------------------------------------------------------
    OTString strAssetTypeID, strAcctRecordFile;
    this->GetIdentifier(strAssetTypeID);
    strAcctRecordFile.Format("%s.a", strAssetTypeID.Get());
    // --------------------------------------------------------------
    OTDB::Storable * pStorable = NULL;
    OTCleanup<OTDB::Storable> theAngel;
    OTDB::StringMap * pMap = NULL;
    // --------------------------------------------------------------
    if (OTDB::Exists(OTFolders::Contract().Get(), strAcctRecordFile.Get())) // the file already exists; let's try to load it up.
        pStorable = OTDB::QueryObject(OTDB::STORED_OBJ_STRING_MAP, OTFolders::Contract().Get(), strAcctRecordFile.Get());
    else // the account records file (for this asset type) doesn't exist.
        pStorable = OTDB::CreateObject(OTDB::STORED_OBJ_STRING_MAP); // this asserts already, on failure.
    
    theAngel.SetCleanupTargetPointer(pStorable); // It will definitely be cleaned up.
    pMap = (NULL == pStorable) ? NULL : dynamic_cast<OTDB::StringMap *>(pStorable);
    // --------------------------------------------------------------
    // It exists.
    //
    if (NULL == pMap) 
    {
        OTLog::vError("%s: Error: failed trying to load or create the account records file for asset type: %s\n", 
                      szFunc, strAssetTypeID.Get());
        return false;
    }
    // -----------------------------------------------
    mapOfStrings &         theMap = pMap->the_map;
    mapOfStrings::iterator map_it = theMap.find(strAcctID.Get());
    
    if (theMap.end() != map_it) // we found it.
    {   // We were ADDING IT, but it was ALREADY THERE. 
        // (Thus, we're ALREADY DONE.)
        // Let's just make sure the right asset type ID is associated with this account 
        // (it better be, since we loaded the account records file based on the asset type ID as its filename...)
        //
        const std::string & str2 = (*map_it).second; // Containing the asset type ID. (Just in case someone copied the wrong file here, 
        // --------------------------------          // every account should map to the SAME asset ID.)

        if (false == strAssetTypeID.Compare(str2.c_str())) // should never happen.
        {
            OTLog::vError("%s: Error: wrong asset type found in account records file...\n For asset type: %s\n "
                          "For account: %s\n Found wrong asset type: %s\n", szFunc, strAssetTypeID.Get(),
                          strAcctID.Get(), str2.c_str());
            return false;
        }

        return true; // already there (no need to add.) + the asset type ID matches.
    }
    // ---------------------------------------------------
    // it wasn't already on the list...

    // ...so add it.
    //
    theMap[strAcctID.Get()] = strAssetTypeID.Get();
    
    // ---------------------------------------------------
    // Then save it back to local storage:
    //
    if (false == OTDB::StoreObject(*pMap, OTFolders::Contract().Get(), strAcctRecordFile.Get()))
    {
        OTLog::vError("%s: Failed trying to StoreObject, while saving updated "
                      "account records file for asset type: %s\n to contain account ID: %s\n", 
                      szFunc, strAssetTypeID.Get(), strAcctID.Get());
        return false;
    }
    // ----------------------------------------------------------------
    // Okay, we saved the updated file, with the account added. (done, success.)
    //
    return true;
}


bool OTAssetContract::EraseAccountRecord(const OTIdentifier & theAcctID)  // removes the account from the list. (When account is deleted.)
{
    //  Load up account list StringMap. Create it if doesn't already exist.
    //  See if account is already there in the map. Erase it, if it is.
    //  Save the StringMap back again. (The account records list for a given asset type.)
    
    const char * szFunc = "OTAssetContract::EraseAccountRecord";    
    // --------------------------------------------------------------
    const OTString     strAcctID(theAcctID);
    // --------------------------------------------------------------
    OTString strAssetTypeID, strAcctRecordFile;
    this->GetIdentifier(strAssetTypeID);
    strAcctRecordFile.Format("%s.a", strAssetTypeID.Get());
    // --------------------------------------------------------------
    OTDB::Storable * pStorable = NULL;
    OTCleanup<OTDB::Storable> theAngel;
    OTDB::StringMap * pMap = NULL;
    // --------------------------------------------------------------
    if (OTDB::Exists(OTFolders::Contract().Get(), strAcctRecordFile.Get())) // the file already exists; let's try to load it up.
        pStorable = OTDB::QueryObject(OTDB::STORED_OBJ_STRING_MAP, OTFolders::Contract().Get(), strAcctRecordFile.Get());
    else // the account records file (for this asset type) doesn't exist.
        pStorable = OTDB::CreateObject(OTDB::STORED_OBJ_STRING_MAP); // this asserts already, on failure.
    
    theAngel.SetCleanupTargetPointer(pStorable); // It will definitely be cleaned up.
    pMap = (NULL == pStorable) ? NULL : dynamic_cast<OTDB::StringMap *>(pStorable);
    // --------------------------------------------------------------
    // It exists.
    //
    if (NULL == pMap) 
    {
        OTLog::vError("%s: Error: failed trying to load or create the account records file for asset type: %s\n", 
                      szFunc, strAssetTypeID.Get());
        return false;
    }
    // -----------------------------------------------
    // Before we can erase it, let's see if it's even there....
    //
    mapOfStrings &         theMap = pMap->the_map;
    mapOfStrings::iterator map_it = theMap.find(strAcctID.Get());
    
    // we found it!
    if (theMap.end() != map_it) //  Acct ID was already there...
    {           
        theMap.erase(map_it); // remove it
    }
    // ---------------------------------------------------
    // it wasn't already on the list...
    // (So it's like success, since the end result is, acct ID will not appear on this list--whether
    // it was there or not beforehand, it's definitely not there now.)
    
    // Then save it back to local storage:
    //
    if (false == OTDB::StoreObject(*pMap, OTFolders::Contract().Get(), strAcctRecordFile.Get()))
    {
        OTLog::vError("%s: Failed trying to StoreObject, while saving updated "
                      "account records file for asset type: %s\n to erase account ID: %s\n", 
                      szFunc, strAssetTypeID.Get(), strAcctID.Get());
        return false;
    }
    // ----------------------------------------------------------------
    // Okay, we saved the updated file, with the account removed. (done, success.)
    //
    return true;
}


// Normally, Asset Contracts do NOT update / rewrite their contents, since their
// primary goal is for the signature to continue to verify.  But when first creating
// a basket contract, we have to rewrite the contents, which is done here.
bool OTAssetContract::CreateBasket(OTBasket & theBasket, OTPseudonym & theSigner)
{
	Release();

	// Grab a string copy of the basket information.
	theBasket.SaveContractRaw(m_strBasketInfo);
	// -------------------------------
    OTString     strTemplate;
    OTASCIIArmor theBasketArmor(m_strBasketInfo);
    // -------------------------------
    m_xmlUnsigned.Concatenate("<?xml version=\"%s\"?>\n", "1.0");
    
    strTemplate.Concatenate("<basketContract version=\"%s\">\n\n", m_strVersion.Get());
    strTemplate.Concatenate("<basketInfo>\n%s</basketInfo>\n\n", theBasketArmor.Get());

    strTemplate.Concatenate("</%s>\n", "basketContract");
    // -------------------------------    
	return this->CreateContract(strTemplate, theSigner);
}


void OTAssetContract::CreateContents()
{
    // ----------------------------------
    m_strVersion = "2.1";  // 2.1 since adding scriptableContract.
    // ----------------------------------
 	m_xmlUnsigned.Release();
    m_xmlUnsigned.Concatenate("<?xml version=\"%s\"?>\n", "1.0");
    // ----------------------------------
    if (m_strBasketInfo.Exists()) // Basket contract
    {
        OTASCIIArmor theBasketArmor(m_strBasketInfo);
        // -------------------------------
        m_xmlUnsigned.Concatenate("<basketContract version=\"%s\">\n\n", m_strVersion.Get());
        m_xmlUnsigned.Concatenate("<basketInfo>\n%s</basketInfo>\n\n", theBasketArmor.Get());
    }
    // ----------------------------------
    else // All other asset contracts.
    {
        // ----------------------------------
        m_xmlUnsigned.Concatenate("<%s version=\"%s\">\n\n", "digitalAssetContract", m_strVersion.Get());
        // --------------------------------------------
        // Entity
        m_xmlUnsigned.Concatenate("<entity shortname=\"%s\"\n"
                                  " longname=\"%s\"\n"
                                  " email=\"%s\"/>\n\n",
                                  m_strEntityShortName.Get(),
                                  m_strEntityLongName .Get(),
                                  m_strEntityEmail    .Get());    
        // --------------------------------------------
        // Issue
        m_xmlUnsigned.Concatenate("<issue company=\"%s\"\n"
                                  " email=\"%s\"\n"
                                  " contractUrl=\"%s\"\n"
                                  " type=\"%s\"/>\n\n",
                                  m_strIssueCompany    .Get(),
                                  m_strIssueEmail      .Get(),
                                  m_strIssueContractURL.Get(),
                                  m_strIssueType       .Get());
        // --------------------------------------------
        // [currency|shares]
        if (m_bIsCurrency)
            m_xmlUnsigned.Concatenate("<currency name=\"%s\" tla=\"%s\" symbol=\"%s\" type=\"%s\" "
                                      "factor=\"%s\" decimal_power=\"%s\" fraction=\"%s\" />\n\n",
                                      m_strCurrencyName        .Get(),
                                      m_strCurrencyTLA         .Get(),
                                      m_strCurrencySymbol      .Get(),
                                      m_strCurrencyType        .Get(),
                                      m_strCurrencyFactor      .Get(),
                                      m_strCurrencyDecimalPower.Get(),
                                      m_strCurrencyFraction    .Get());
        else if (m_bIsShares)
            m_xmlUnsigned.Concatenate("<shares name=\"%s\" symbol=\"%s\" type=\"%s\" issuedate=\"%s\" />\n\n",
                                      m_strCurrencyName  .Get(),
                                      m_strCurrencySymbol.Get(),
                                      m_strCurrencyType  .Get(),
                                      m_strIssueDate     .Get());
    }
    
    //Add any scripted bylaws to the asset contract    
    if ((m_mapBylaws.size()>0)) {
	    m_xmlUnsigned.Concatenate("<scriptableContract\n numBylaws=\"%d\" >\n\n", m_mapBylaws.size());

	    FOR_EACH(mapOfBylaws, m_mapBylaws) {
		    OTBylaw * pBylaw = (*it).second;
		    OT_ASSERT(NULL != pBylaw);

		    pBylaw->Serialize(m_xmlUnsigned, false);
	    }

	    m_xmlUnsigned.Concatenate("</scriptableContract>\n\n");
    }
    
    // --------------------------------------------
    // This is where OTContract scribes m_xmlUnsigned with its keys, conditions, etc.
    this->CreateInnerContents();    
    // --------------------------------------------
	m_xmlUnsigned.Concatenate("</%s>\n", m_strBasketInfo.Exists() ? "basketContract" : "digitalAssetContract");
    // --------------------------------------------   
}


// return -1 if error, 0 if nothing, and 1 if the node was processed.
//
int32_t OTAssetContract::ProcessXMLNode(IrrXMLReader*& xml)
{
  const char * szFunc = "OTAssetContract::ProcessXMLNode";
  int32_t nReturnVal = OTContract::ProcessXMLNode(xml);

  // Here we call the parent class first.
  // If the node is found there, or there is some error,
  // then we just return either way.  But if it comes back
  // as '0', then nothing happened, and we'll continue executing.
  //
  // -- Note you can choose not to call the parent if
  // you don't want to use any of those xml tags.

  if (nReturnVal == 1 || nReturnVal == (-1))
	  return nReturnVal;

  const OTString strNodeName(xml->getNodeName());

  if (strNodeName.Compare("digitalAssetContract"))
  {
	  m_strVersion = xml->getAttributeValue("version");					
	  
	  OTLog::vOutput(1, "\n"
			  "===> Loading XML portion of asset contract into memory structures...\n\n"
			  "Digital Asset Contract: %s\nContract version: %s\n----------\n", m_strName.Get(), m_strVersion.Get());
	  nReturnVal = 1;
  }
  else if (strNodeName.Compare("basketContract"))
  {
	  m_strVersion = xml->getAttributeValue("version");					
	  
	  OTLog::vOutput(1, "\n"
			  "===> Loading XML portion of basket contract into memory structures...\n\n"
			  "Digital Basket Contract: %s\nContract version: %s\n----------\n", m_strName.Get(), m_strVersion.Get());
	  nReturnVal = 1;
  }
  else if (strNodeName.Compare("basketInfo")) 
  {		
	  if (false == OTContract::LoadEncodedTextField(xml, m_strBasketInfo))
	  {
		  OTLog::Error("Error in OTAssetContract::ProcessXMLNode: basketInfo field without value.\n");
		  return (-1); // error condition
	  }
	  nReturnVal = 1;
  }	
  else if (strNodeName.Compare("issue"))
  {
	  m_strIssueCompany     = xml->getAttributeValue("company");
	  m_strIssueEmail       = xml->getAttributeValue("email");
	  m_strIssueContractURL = xml->getAttributeValue("contractUrl");
	  m_strIssueType        = xml->getAttributeValue("type");
	  
	  OTLog::vOutput(2, "Loaded Issue company: %s\nEmail: %s\nContractURL: %s\nType: %s\n----------\n",
			  m_strIssueCompany.Get(), m_strIssueEmail.Get(), m_strIssueContractURL.Get(),
			  m_strIssueType.Get());
	  nReturnVal = 1;
  }
  // TODO security validation: validate all the above and below values.
  else if (strNodeName.Compare("currency") )    
  {
  m_bIsCurrency             = true;  // silver grams
  m_bIsShares               = false;        

	  m_strName                 = xml->getAttributeValue("name");
	  m_strCurrencyName         = xml->getAttributeValue("name");
	  m_strCurrencySymbol       = xml->getAttributeValue("symbol");
	  m_strCurrencyType         = xml->getAttributeValue("type");

	  m_strCurrencyTLA          = xml->getAttributeValue("tla");
	  m_strCurrencyFactor       = xml->getAttributeValue("factor");
	  m_strCurrencyDecimalPower = xml->getAttributeValue("decimal_power");
	  m_strCurrencyFraction     = xml->getAttributeValue("fraction");
	  
	  OTLog::vOutput(2, "Loaded %s, Name: %s, TLA: %s, Symbol: %s\n"
		  "Type: %s, Factor: %s, Decimal Power: %s, Fraction: %s\n----------\n", 
		  strNodeName.Get(),
		  m_strCurrencyName.Get(), m_strCurrencyTLA.Get(), m_strCurrencySymbol.Get(),
		  m_strCurrencyType.Get(), m_strCurrencyFactor.Get(), m_strCurrencyDecimalPower.Get(),
		  m_strCurrencyFraction.Get());
	  nReturnVal = 1;
  }

    //  share_type some type, for example, A or B, or NV (non voting)
    //        
    //  share_name this is the int64_t legal name of the company
    //        
    //  share_symbol this is the trading name (8 chars max), as it might be 
    //      displayed in a market contect, and should be unique within some given market
    //        
    //  share_issue_date date of start of this share item (not necessarily IPO)

  else if (strNodeName.Compare("shares") ) {
  m_bIsShares           = true;        // shares of pepsi
  m_bIsCurrency         = false;

	  m_strName			  = xml->getAttributeValue("name");
	  m_strCurrencyName	  = xml->getAttributeValue("name");	
	  m_strCurrencySymbol   = xml->getAttributeValue("symbol");
	  m_strCurrencyType     = xml->getAttributeValue("type");

	  m_strIssueDate        = xml->getAttributeValue("issuedate");
	  
	  OTLog::vOutput(2, "Loaded %s, Name: %s, Symbol: %s\n"
		  "Type: %s, Issue Date: %s\n----------\n", 
		  strNodeName.Get(),
		  m_strCurrencyName.Get(), m_strCurrencySymbol.Get(),
		  m_strCurrencyType.Get(),
		  m_strIssueDate.Get());
	  nReturnVal = 1;
  } 
  else if (strNodeName.Compare("scriptableContract")) {
    
    // Load up the Bylaws.
    OTString strNumBylaws = xml->getAttributeValue("numBylaws");
    int32_t nBylawCount	= strNumBylaws.Exists() ? atoi(strNumBylaws.Get()) : 0;
    if (nBylawCount > 0) {
      while (nBylawCount-- > 0) {
	if (false == SkipToElement(xml)){
		OTLog::vOutput(0, "%s: Failure: Unable to find expected element for bylaw. \n", szFunc);
		return (-1);
	}

	if (!strcmp("bylaw", xml->getNodeName())) {
	  OTString strName		= xml->getAttributeValue("name"); // bylaw name
	  OTString strLanguage	= xml->getAttributeValue("language"); // The script language used in this bylaw.

	  OTString strNumVariable		= xml->getAttributeValue("numVariables"); // number of variables on this bylaw.
	  OTString strNumClauses		= xml->getAttributeValue("numClauses"); // number of clauses on this bylaw.
	  
	  OTBylaw * pBylaw = new OTBylaw(strName.Get(), strLanguage.Get());

	  OT_ASSERT(NULL != pBylaw);

	  // ---------------------------------------------------------------------------
	  //
	  // LOAD VARIABLES AND CONSTANTS.
	  //
	  int32_t nCount	= strNumVariable.Exists() ? atoi(strNumVariable.Get()) : 0;
	  if (nCount > 0) {
	      while (nCount-- > 0) {
		  if (false == OTContract::SkipToElement(xml)) {
		      OTLog::vError("%s: Error finding expected next element for variable.\n", szFunc);
		      delete pBylaw; pBylaw=NULL;
		      return (-1);
		  }
		  // -----------------------------------------------
		  if ((xml->getNodeType() == irr::io::EXN_ELEMENT) && (!strcmp("variable", xml->getNodeName()))) {
		      OTString strVarName = xml->getAttributeValue("name"); // Variable name (if needed in script code)
		      OTString strVarValue = xml->getAttributeValue("value"); // Value stored in variable (If this is "true" then a real value is expected in a text field below. Otherwise, it's assumed to be a BLANK STRING.)
		      OTString strVarType = xml->getAttributeValue("type"); // string or int64_t
		      OTString strVarAccess = xml->getAttributeValue("access"); // constant, persistent, or important.

		      // ----------------------------------

		      if (!strVarName.Exists() || !strVarType.Exists() || !strVarAccess.Exists()) {
			  OTLog::vError("%s: Expected missing name, type, or access type in variable.\n", szFunc);
			  delete pBylaw; pBylaw=NULL;
			  return (-1);
		      }
		      // ---------------------------------------
		      // See if the same-named variable already exists on ANY of the OTHER BYLAWS
		      // (There can only be one variable on an OTAssetContract with a given name.)
		      //
		      OTVariable * pVar = this->GetVariable(strVarName.Get());

		      if (NULL != pVar) { // Uh-oh, it's already there!
			  OTLog::vOutput(0, "%s: Error loading variable named %s, since one was "
					  "already there on one of the bylaws.\n", szFunc, strVarName.Get());
			  delete pBylaw; pBylaw=NULL;
			  return (-1);
		      }
		      // The AddVariable call below checks to see if it's already there, but only for the
		      // currently-loading bylaw.
		      // Whereas the above call checks this OTScriptable for all the variables on the already-loaded bylaws.
		      // ----------------------------------
		      //
		      // VARIABLE TYPE AND ACCESS TYPE
		      //
		      OTVariable::OTVariable_Type theVarType = OTVariable::Var_Error_Type;

		      if (strVarType.Compare("integer"))
			  theVarType = OTVariable::Var_Integer;
		      else if (strVarType.Compare("string"))
			  theVarType = OTVariable::Var_String;
		      else if (strVarType.Compare("bool"))
			  theVarType = OTVariable::Var_Bool;
		      else
			  OTLog::vError("%s: Bad variable type: %s.\n", szFunc, strVarType.Get());

		      // ---------

		      OTVariable::OTVariable_Access theVarAccess = OTVariable::Var_Error_Access;

		      if (strVarAccess.Compare("constant"))
			  theVarAccess = OTVariable::Var_Constant;
		      else if (strVarAccess.Compare("persistent"))
			  theVarAccess = OTVariable::Var_Persistent;
		      else if (strVarAccess.Compare("important"))
			  theVarAccess = OTVariable::Var_Important;
		      else
			  OTLog::vError("%s: Bad variable access type: %s.\n", szFunc, strVarAccess.Get());

		      // ---------

		      if ((OTVariable::Var_Error_Access == theVarAccess) ||
			  (OTVariable::Var_Error_Type == theVarType))
		      {
			  OTLog::vError("%s: Error loading variable to bylaw: "
					"bad type (%s) or access type (%s).\n",
					szFunc, strVarType.Get(), strVarAccess.Get());
			  delete pBylaw; pBylaw=NULL;
			  return (-1);
		      }
		      // ---------------------------------------

		      bool bAddedVar = false;
		      const std::string str_var_name = strVarName.Get();

		      switch (theVarType) {
			  case OTVariable::Var_Integer:
			      if (strVarValue.Exists()) {
				  const int32_t nVarValue = atoi(strVarValue.Get());
				  bAddedVar = pBylaw->AddVariable(str_var_name, nVarValue, theVarAccess);
			      } else {
				  OTLog::vError("%s: No value found for integer variable: %s\n", szFunc,
						strVarName.Get());
				  delete pBylaw; pBylaw=NULL;
				  return (-1);
			      }
			      break;
			      // ---------------------------------
			  case OTVariable::Var_Bool:			    
			      if (strVarValue.Exists()) {
				  const bool bVarValue = strVarValue.Compare("true") ? true : false;
				  bAddedVar = pBylaw->AddVariable(str_var_name, bVarValue, theVarAccess);
			      } else {
				  OTLog::vError("%s: No value found for bool variable: %s\n", szFunc,
						strVarName.Get());
				  delete pBylaw; pBylaw=NULL;
				  return (-1);
			      }
			      break;
			      // ---------------------------------
			  case OTVariable::Var_String:                                 {
			      // I realized I should probably allow empty strings.  :-P
			      if (strVarValue.Exists() && strVarValue.Compare("exists")) {
				  strVarValue.Release(); // probably unnecessary.
				  if (false == OTContract::LoadEncodedTextField(xml, strVarValue)) {
				      OTLog::vError("%s: No value found for string variable: %s\n", szFunc,
						    strVarName.Get());
				      delete pBylaw; pBylaw=NULL;
				      return (-1);
				  }
			      } else {
				  strVarValue.Release(); // Necessary. If it's going to be a blank string, then let's make sure.
			      }

			      const std::string str_var_value = strVarValue.Get();
			      bAddedVar = pBylaw->AddVariable(str_var_name, str_var_value, theVarAccess);
			  }
			      break;
			  default:
			      OTLog::vError("%s: Wrong variable type... "
					    "somehow AFTER I should have already detected it...\n", szFunc);
			      delete pBylaw; pBylaw=NULL;
			      return (-1);
		      }
		      // -------------------------------------------------

		      if (false == bAddedVar) {
			  OTLog::vError("%s: Failed adding variable to bylaw.\n", szFunc);
			  delete pBylaw; pBylaw=NULL;
			  return (-1);
		      }
		  } else {
		      OTLog::vError("%s: Expected variable element in bylaw.\n", szFunc);
		      delete pBylaw; pBylaw=NULL;
		      return (-1); // error condition
		  }
	      } // while
	  }
	  
	  
	  // LOAD CLAUSES
	  //
	  nCount	= strNumClauses.Exists() ? atoi(strNumClauses.Get()) : 0;
	  if (nCount > 0) {
	      while (nCount-- > 0) {                            
		  const char	*	pElementExpected	= "clause";
		  OTString		strTextExpected; // clause's script code will go here.

		  mapOfStrings	temp_MapAttributes;
		  //
		  // This map contains values we will also want, when we read the clause...
		  // (The OTContract::LoadEncodedTextField call below will read all the values
		  // as specified in this map.)
		  //
		  //
		  temp_MapAttributes.insert(std::pair<std::string, std::string>("name", ""));
		  
  // 			    //Load the node data into an ASCII Armor object 
  // 			    OTASCIIArmor possiblyASCIIArmoredText = new OTASCIIArmor(xml->getNodeData().c_str());
  // 			    try{
  // 			      OTString outputText;
  // 			      OTLog::vOutput(0, "Trying to unpack the Clause text.");
  // 			      if(false == possiblyAsCIIArmoredText.GetAndUnpackString(outputText)){
  // 				OTLog::vOutput(0, "Failed unpacking the Clause text.  Will convert it now.");
  // 				//Failed, but not catastrophically.  Assume its plain text
  // 				//Drop into the catch block to set and pack the string, then update the xml
  // 				throw 1;
  // 			      }			      
  // 			    }catch(...){
  // 			      //String is not ASCII Armored. Lets do that and then update the xml
  // 			      OTLog::vOutput(0, "Converting the Clause text to packed, base64 encoded text");
  // 			      possiblyASCIIArmoredText.SetAndPackString(xml->getNodeData());
  // 			    //strTextExpected = xml->getNodeData().c_str();
  // 			    }
		  
		  
		  if (false == OTContract::LoadEncodedTextFieldByName(xml, strTextExpected, pElementExpected, &temp_MapAttributes)) // </clause>
		  {
		      OTLog::vError("%s: Error: "
				    "Expected %s element with text field.\n", szFunc,
				    pElementExpected);
		      delete pBylaw; pBylaw = NULL;
		      return (-1); // error condition
		  }

		  // Okay we now have the script code in strTextExpected. Next, let's read the clause's NAME
		  // from the map. If it's there, and presumably some kind of harsh validation for both, then
		  // create a clause object and add to my list here.
		  // ------------------------------------------

		  mapOfStrings::iterator it = temp_MapAttributes.find("name");

		  if ((it != temp_MapAttributes.end())) { // We expected this much.
		      std::string & str_name = (*it).second;

		      if (str_name.size() > 0) { // SUCCESS
			  // See if the same-named clause already exists on ANY of the OTHER BYLAWS
			  // (There can only be one clause on an OTAssetContract with a given name.)
			  //
			  OTClause * pClause = this->GetClause(str_name.c_str());

			  if (NULL != pClause) { // Uh-oh, it's already there!
			      OTLog::vOutput(0, "%s: Error loading clause named %s, since one was already "
					      "there on one of the bylaws.\n", szFunc, str_name.c_str());
			      delete pBylaw; pBylaw=NULL;
			      return (-1);
			  } else if (false == pBylaw->AddClause(str_name.c_str(), strTextExpected.Get())) {
			      OTLog::vError("%s: Failed adding clause to bylaw.\n", szFunc);
			      delete pBylaw; pBylaw=NULL;
			      return (-1); // error condition
			  }
		      }
		      // else it's empty, which is expected if nothing was there, since that's the default value
		      // that we set above for "name" in temp_MapAttributes.
		      else
		      {
			  OTLog::vError("%s: Expected clause name.\n", szFunc);
			  delete pBylaw; pBylaw=NULL;
			  return (-1); // error condition
		      }
		  } else {
		      OTLog::vError("%s: Strange error: couldn't find name AT ALL.\n", szFunc);
		      delete pBylaw; pBylaw=NULL;
		      return (-1); // error condition
		  }
	      } // while
	  } // if strNumClauses.Exists() && nCount > 0

	  if (AddBylaw(*pBylaw)) {
	      OTLog::vOutput(2, "%s: Loaded Bylaw: %s\n", szFunc,
			      pBylaw->GetName().Get());
	  } else {
	      OTLog::vError("%s: Failed loading Bylaw: %s\n", szFunc,
			    pBylaw->GetName().Get());
	      delete pBylaw; pBylaw = NULL;
	      return (-1); // error condition
	  }
	} else {
		OTLog::vError("%s: Expected bylaw element.\n", szFunc);
		return (-1); // error condition
	}
      } // while
    }
    nReturnVal = 1;
  }

  return nReturnVal;
}






OTAssetContract * OTAssetContract::InstantiateAssetContract(const OTString & strInput)
{
// 	static char buf[45] = "";
// 	// ---------------------------------
// 	if (false == strInput.Exists())
//     {
//         OTLog::vError("%s: Failure: Input string is empty.\n", __FUNCTION__);
//         return NULL;
//     }
//     // --------------------------------------------------------------------
//     OTString strContract(strInput);
// 
//     if (false == strContract.DecodeIfArmored(false)) // bEscapedIsAllowed=true by default.
//     {
//         OTLog::vError("%s: Input string apparently was encoded and then failed decoding. Contents: \n%s\n",
//                       __FUNCTION__, strInput.Get());
//         return NULL;
//     }
//     // ------------------------------------------
//     // At this point, strContract contains the actual contents, whether they
//     // were originally ascii-armored OR NOT. (And they are also now trimmed, either way.)
//     //
// 	strContract.reset(); // for sgets
// 	buf[0] = 0; // probably unnecessary.
// 	bool bGotLine = strContract.sgets(buf, 40);
// 
// 	if (!bGotLine)
// 		return NULL;
// 	// --------------------------------
//     OTCronItem * pItem = NULL;
// 
// 	OTString strFirstLine(buf);
// 	strContract.reset(); // set the "file" pointer within this string back to index 0.
// 
// 	// Now I feel pretty safe -- the string I'm examining is within
// 	// the first 45 characters of the beginning of the contract, and
// 	// it will NOT contain the escape "- " sequence. From there, if
// 	// it contains the proper sequence, I will instantiate that type.
// 	if (!strFirstLine.Exists() || strFirstLine.Contains("- -"))
// 		return NULL;
// 
// 	// There are actually two factories that load smart contracts. See OTCronItem.
// 	//
// 	else if (strFirstLine.Contains("-----BEGIN SIGNED SMARTCONTRACT-----"))  // this string is 36 chars long.
// 	{	pItem = new OTSmartContract();	OT_ASSERT(NULL != pItem); }
// 
// 	// Coming soon.
// //	else if (strFirstLine.Contains("-----BEGIN SIGNED ENTITY-----"))  // this string is 29 chars long.
// //	{	pItem = new OTEntity();			OT_ASSERT(NULL != pItem); }
// 
// 	// The string didn't match any of the options in the factory.
// 	if (NULL == pItem)
// 		return NULL;
// 
// 	// Does the contract successfully load from the string passed in?
// 	if (pItem->LoadContractFromString(strContract))
// 		return pItem;
// 	else
// 		delete pItem;


	return NULL;
}




// VALIDATING IDENTIFIERS IN OTSCRIPTABLE.
// Only alphanumerics are valid, or '_' (underscore)
bool OTAssetContract::is_ot_namechar_invalid(char c) {
	return !(isalnum(c) || (c == '_'));
}


// static
bool OTAssetContract::ValidateName(const std::string str_name) {
	if (str_name.size() <= 0) {
		OTLog::Error("OTScriptable::ValidateName: Name has zero size.\n");
		return false;
	} else if (find_if(str_name.begin(), str_name.end(), is_ot_namechar_invalid) != str_name.end()) {
		OTLog::vError("OTScriptable::ValidateName: Name fails validation testing: %s\n", str_name.c_str());
		return false;
	}

	return true;
}


void OTAssetContract::RegisterOTNativeCallsWithScript(OTScript & theScript){
#ifdef OT_USE_SCRIPT_CHAI
	using namespace chaiscript;
	
	OTScriptChai * pScript = dynamic_cast<OTScriptChai *> (&theScript);

	if (NULL != pScript){
		OT_ASSERT(NULL != pScript->chai)
		
		pScript->chai->add(fun(&OTAssetContract::GetTime), "get_time");
		
		
		pScript->chai->add(fun(&OTAssetContract::GetPi), "get_pi");
		pScript->chai->add(fun(&OTAssetContract::GetSine), "sin");
		pScript->chai->add(fun(&OTAssetContract::GetCosine), "cos");
		pScript->chai->add(fun(&OTAssetContract::GetArcsine), "asin");
		pScript->chai->add(fun(&OTAssetContract::GetSquareRoot), "sqrt");
		pScript->chai->add(fun(&OTAssetContract::GetExponential), "exp");
		pScript->chai->add(fun(&OTAssetContract::GetNaturalLogarithm), "ln");
		//pScript->chai->add(fun(&OTSmartContract::GetAcctBalance, this), "get_acct_balance");
		
	}else
#endif // OT_USE_SCRIPT_CHAI
	{
		OTLog::Error("OTAssetContract::RegisterOTNativeCallsWithScript: Failed dynamic casting OTScript to OTScriptChai \n");
	}
}



// Returns a string, containing seconds as int32_t. (Time in seconds.)
std::string OTAssetContract::GetTime(){ 
    const time64_t  CURRENT_TIME = OTTimeGetCurrentTime();
    const int64_t   lTime = OTTimeGetSecondsFromTime(CURRENT_TIME);
    // ----------------------------------
    OTString strTime;
    strTime.Format("%lld", lTime);
    return	strTime.Get();
}
// Returns a string, containing Pi
std::string OTAssetContract::GetPi(){ 
    OTString strPi;
    strPi.Format("%lld", M_PI);
    return strPi.Get();
}
// Returns a string, containing the sine value for the given angle in radians 
std::string OTAssetContract::GetSine(const std::string angleRadians){ 
    double angleRadiansValue = atof(angleRadians.c_str());
    double result = sin(angleRadiansValue);
    OTString strSine;
    strSine.Format("%lld", result);
    return strSine.Get();
}
// Returns a string, containing the cosine value for the given angle in radians 
std::string OTAssetContract::GetCosine(const std::string angleRadians){ 
    double angleRadiansValue = atof(angleRadians.c_str());
    double result = cos(angleRadiansValue);
    OTString strCosine;
    strCosine.Format("%lld", result);
    return strCosine.Get();
}
// Returns a string, containing the arcsine value for the given angle in radians 
std::string OTAssetContract::GetArcsine(const std::string angleRadians){ 
    double angleRadiansValue = atof(angleRadians.c_str());
    double result = asin(angleRadiansValue);
    OTString strArcsine;
    strArcsine.Format("%lld", result);
    return strArcsine.Get();
}
// Returns a string, containing the square root of the supplied value
std::string OTAssetContract::GetSquareRoot(const std::string value){ 
    double valueAsDouble = atof(value.c_str());
    double result = sqrt(valueAsDouble);
    OTString strSquareRoot;
    strSquareRoot.Format("%lld", result);
    return strSquareRoot.Get();
}
// Returns a string, containing the exponential of the supplied value
std::string OTAssetContract::GetExponential(const std::string value){ 
    double valueAsDouble = atof(value.c_str());
    double result = exp(valueAsDouble);
    OTString strExponential;
    strExponential.Format("%lld", result);
    return strExponential.Get();
}
// Returns a string, containing the natural logarithm of the supplied value
std::string OTAssetContract::GetNaturalLogarithm(const std::string value){ 
    double valueAsDouble = atof(value.c_str());
    double result = log(valueAsDouble);
    OTString strNaturalLogarithm;
    strNaturalLogarithm.Format("%lld", result);
    return strNaturalLogarithm.Get();
}





bool OTAssetContract::ExecuteClause(OTClause & theCallbackClause, mapOfVariables & theParameters, OTVariable & varReturnVal)
{
	const std::string str_clause_name	= theCallbackClause.GetName().Exists() ?
											theCallbackClause.GetName().Get() : "";
	OT_ASSERT(OTAssetContract::ValidateName(str_clause_name));

	OTBylaw * pBylaw = theCallbackClause.GetBylaw();
	OT_ASSERT(NULL != pBylaw);
	// -------------------------------------------------
	// By this point, we have the clause we are executing as theCallbackClause,
	// and we have the Bylaw it belongs to, as pBylaw.
	// ----------------------------------------

	const std::string str_code		=	theCallbackClause.GetCode();	// source code for the script.
	const std::string str_language	=	pBylaw->GetLanguage();			// language it's in. (Default is "chai")

	_SharedPtr<OTScript> pScript = OTScriptFactory(str_language, str_code);

	// ---------------------------------------------------------------
	//
	// SET UP THE NATIVE CALLS, REGISTER THE PARTIES, REGISTER THE VARIABLES, AND EXECUTE THE SCRIPT.
	//
	if (pScript)
	{
		// Register the special server-side native OT calls we make available to all scripts.
		//
		this->RegisterOTNativeCallsWithScript(*pScript);

		// ---------------------------------------
		// Add the parameters...
		//
		FOR_EACH(mapOfVariables, theParameters)
		{
			const std::string str_var_name	= (*it).first;
			OTVariable * pVar				= (*it).second;
			OT_ASSERT((NULL != pVar)&&(str_var_name.size() > 0));
			// ---------------------------------------------------
			pVar->RegisterForExecution(*pScript);
		}

		// ---------------------------------------
		// Also need to loop through the Variables on pBylaw and register those as well.
		//
		pBylaw->RegisterVariablesForExecution(*pScript); // This sets all the variables as CLEAN so we can check for dirtiness after execution.
		// ****************************************

        

		if (false == pScript->ExecuteScript(&varReturnVal)){
			OTLog::vError("OTAssetContract::ExecuteClause: Error while running cclause: %s\n",
						 theCallbackClause.GetName().Get());
		}else{
			OTLog::vOutput(0, "OTAssetContract::ExecuteClause: Successfully executed clause: %s\n\n",
						   theCallbackClause.GetName().Get());
			return true;
		}
	}
	// ---------------------------------------------------------------
	else
	{
		OTLog::Error("OTAssetContract::ExecuteClause: Error instantiating script!\n");
	}


	return false;
}


// Find the first (and hopefully the only) clause on this assetContract object,
// with a given name. (Searches ALL Bylaws on *this.)
OTClause * OTAssetContract::GetClause(const std::string str_clause_name)
{
	if (false == OTAssetContract::ValidateName(str_clause_name)) // this logs, FYI.
	{
		OTLog::vError("%s: Error: invalid name.\n", __FUNCTION__);
		return NULL;
	}
	// --------------------------------
	FOR_EACH(mapOfBylaws, m_mapBylaws)
	{
		OTBylaw * pBylaw = (*it).second;
		OT_ASSERT(NULL != pBylaw);
		// -------------------------
		OTClause * pClause = pBylaw->GetClause(str_clause_name);

		if (NULL != pClause) // found it.
			return pClause;
	}

	return NULL;
}


OTBylaw * OTAssetContract::GetBylaw(const std::string str_bylaw_name){
  
	if (false == OTAssetContract::ValidateName(str_bylaw_name)) {
		OTLog::vError("%s: Error: invalid name.\n", __FUNCTION__);
		return NULL;
	}
	
	mapOfBylaws::iterator iii = m_mapBylaws.find(str_bylaw_name);

	if (m_mapBylaws.end() == iii){
		return NULL;
	}
	
	OTBylaw * pBylaw = (*iii).second;
	OT_ASSERT(NULL != pBylaw);

	return pBylaw;
}

OTBylaw * OTAssetContract::GetBylawByIndex(int32_t nIndex){
  
    if ((nIndex < 0) || (nIndex >= static_cast<int64_t>(m_mapBylaws.size()))) {
        OTLog::vError("%s: Index out of bounds: %d\n", __FUNCTION__, nIndex);
    }else {
        int32_t nLoopIndex = -1; // will be 0 on first iteration.

        FOR_EACH(mapOfBylaws, m_mapBylaws)
        {
            OTBylaw * pBylaw = (*it).second;
            OT_ASSERT(NULL != pBylaw);
	    
            ++nLoopIndex; // 0 on first iteration.

            if (nLoopIndex == nIndex)
                return pBylaw;
        }
    }
    return NULL;
}

// Look up the first (and hopefully only) variable registered for a given name.
// (Across all of my Bylaws)
//
OTVariable * OTAssetContract::GetVariable(const std::string str_VarName) {
	if (false == OTAssetContract::ValidateName(str_VarName)) { 
		OTLog::Error("OTAssetContract::GetVariable:  Error: invalid name.\n");
		return NULL;
	}

	FOR_EACH(mapOfBylaws, m_mapBylaws) {
		OTBylaw * pBylaw = (*it).second;
		OT_ASSERT(NULL != pBylaw);

		OTVariable * pVar = pBylaw->GetVariable(str_VarName);

		if (NULL != pVar) // found it.
			return pVar;
	}

	return NULL;
}



bool OTAssetContract::AddBylaw(OTBylaw & theBylaw){
	const std::string str_name = theBylaw.GetName().Get();

	if (false == OTAssetContract::ValidateName(str_name)) {
		OTLog::Error("OTAssetContract::AddBylaw:  Error: invalid name.\n");
		return false;
	}

	if (m_mapBylaws.find(str_name) == m_mapBylaws.end()) {
		// Careful:  This ** DOES ** TAKE OWNERSHIP!  theBylaw will get deleted when this OTAssetContract is.
		m_mapBylaws.insert( std::pair<std::string, OTBylaw *>(str_name, &theBylaw)) ;

		theBylaw.SetOwnerAgreement(*this);

		return true;
	} else {
		OTLog::Output(0, "OTAssetContract::AddBylaw: Failed attempt: bylaw already exists on asset contract.\n ");
	}

	return false;
}


bool OTAssetContract::Compare(OTAssetContract & rhs){
	const char * szFunc = "OTAssetContract::Compare";
	if (this->GetBylawCount() != rhs.GetBylawCount()) {
		OTLog::vOutput(0, "%s: The number of bylaws does not match.\n", szFunc);
		return false;
	}
	
	FOR_EACH_CONST(mapOfBylaws, m_mapBylaws) {
		const std::string str_bylaw_name = (*it).first;
		OTBylaw * pBylaw = (*it).second;
		OT_ASSERT(NULL != pBylaw);

		OTBylaw * p2 = rhs.GetBylaw(str_bylaw_name);

		if (NULL == p2) {
			OTLog::vOutput(0, "%s: Unable to find bylaw %s on rhs.\n", szFunc,
						   str_bylaw_name.c_str());
			return false;
		} else if ( ! pBylaw->Compare(*p2) ) {
			OTLog::vOutput(0, "%s: Bylaws don't match: %s.\n", szFunc,
						   str_bylaw_name.c_str());
			return false;
		}
	}
	
	return true;
}












