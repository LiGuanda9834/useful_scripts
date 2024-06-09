#include <iostream>
#include <cstring>
#include <zlib.h>

using namespace std;

int main(int argv, char* argc[])
{
   if(argv != 2)
      cout<< "error!" <<endl;
      
   gzFile gzfile;
   gzfile = gzopen(argc[1],"rb");
   char buf[1024];
   int bufsize = 0;
   string str;
   string IF = " IF ";
   bool hasIf = false;
   do
   {
      if(!gzgets(gzfile, buf, 1024))
      {
         break;
      }
      str = buf;
      if( str.find(IF) != string::npos)
      {
         hasIf = true;
      }
      bufsize = strlen(buf);
   }while(bufsize > 0);

   gzclose(gzfile);
   if(hasIf == false)
      cout<<argc[1] <<endl;
   return 1;
}
