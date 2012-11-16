unsigned int getutf8(const char*s){
    unsigned char c=s[0];
    if(c<0xF0){
        if(c<0xE0){
            if(c<0xC0){
                if(c<0x80)
                    return c;
                else
                    return 0xFFFD;
            }else{
                unsigned char d=s[1];
                if((d&0xC0)!=0x80)
                    return 0xFFFD;
                return ((c&0x1F)<<6)|(d&0x3F);
            }
        }else{
            unsigned char d=s[1];
            if((d&0xC0)!=0x80)
                return d&0x7F;//0xFFFD;
            unsigned char e=s[2];
            if((e&0xC0)!=0x80)
                return 0xFFFD;
            int a=((c&0x0F)<<12)|((d&0x3F)<<6)|(e&0x3F);
            return a;
        }
    }else
        return 0xFFFD;
}

unsigned int getutf8len(const char*s){
    unsigned char c=s[0];
    if(c<0xF0){
        if(c<0xE0){
            if(c<0xC0){
                if(c<0x80)
                    return 1;
                else
                    return 1;
            }else{
                unsigned char d=s[1];
                if((d&0xC0)!=0x80)
                    return 1;
                return 2;
            }
        }else{
            unsigned char d=s[1];
            if((d&0xC0)!=0x80)
                return 1;
            unsigned char e=s[2];
            if((e&0xC0)!=0x80)
                return 2;
            return 3;
        }
    }else
        return 4;
}

