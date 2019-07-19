/*****************************************************************************
** FUNCTION:   validate_CountryCode
**
** PURPOSE:    check the format of the country code and make sure it's valid
**
** PARAMETERS: none
**
** RETURNS:    0 - CountryCode is valid, proceed with snmp set
**             1 - CountryCode is invalid
******************************************************************************/
static int validate_CountryCode (char *str)
{
   const EMTAMGMTCOUNTRYCODEMAP      *codeMap = countryCodeMap;

   char *p = str;

   if (!str )
   {
      return -1;   /* Too bad */
   }

   /* convert country code to upper case */
   *p = (char)toupper(*p);
   p++;
   *p = (char)toupper(*p);

   /*
   ** Search for country code match
   */
   while (( strncmp(codeMap->abbrev, str, SIZE_emtaCountryCode)) && (strcmp(codeMap->abbrev, "")))
   {
      codeMap++;
   }

   if(( codeMap->emtaCountryCode == -1 ) || (codeMap->supported == 0) )
   {
      LOG_DBG((LOG_MOD_SNMP,"validate_CountryCode():  Unrecognized Country Code"));
      return -1;
   }

   return codeMap->emtaCountryCode;
}  /* end of validate_CountryCode() */