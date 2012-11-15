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
                if(d&0xC0!=0x80)
                    return 0xFFFD;
                return ((c&0x1C)<<6)|(d&0x3C);
            }
        }else{
            unsigned char d=s[1];
            if(d&0xC0!=0x80)
                return 0xFFFD;
            unsigned char e=s[2];
            if(d&0xC0!=0x80)
                return 0xFFFD;
            return ((c&0x0C)<<12)|((d&0x3C)<<6)|(d&0x3C);
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
                if(d&0xC0!=0x80)
                    return 1;
                return 2;
            }
        }else{
            unsigned char d=s[1];
            if(d&0xC0!=0x80)
                return 1;
            unsigned char e=s[2];
            if(d&0xC0!=0x80)
                return 2;
            return 3;
        }
    }else
        return 4;
}

