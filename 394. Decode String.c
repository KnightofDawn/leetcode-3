/*
394. Decode String

Given an encoded string, return it's decoded string.


The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.


You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].


Examples:
s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
*/

struct node {
    char *leading_string;
    int leading_len;
    int repeat;
};
​
char* decodeString(char* s) {
    struct node stack[100], *p;
    int sp = 0;
    
    int n;
    
    char *buff = NULL;
    int sz, len;
    
    char *newbuff = NULL;
    int newsz, newlen;
    
    char *tmp;
​
    n = 0;
    p = &stack[sp];
    while (*s) {
        if (*s == '[') {
            p->leading_string = buff;
            p->leading_len = len;
            buff = NULL;
            sz = len = 0;
            
            p->repeat = n;
            n = 0;
            
            sp ++;
            p = &stack[sp];
        } else if (*s == ']') {
            // pop and expand
            p = &stack[-- sp];
            
            newlen = p->leading_len + p->repeat * len;
            newsz = newlen + 10;
            newbuff = malloc(newsz * sizeof(char));
            //assert(newbuff);
            if (p->leading_string) {
                sprintf(newbuff, "%s", p->leading_string);
                free(p->leading_string);
            }
            tmp = newbuff + p->leading_len;
            //printf("repeat: %d, buff: %s, len: %d\n", p->repeat, buff, len);
            while (p->repeat) {
                strcat(tmp, buff);
                tmp += len;
                p->repeat --;
            }
            newbuff[newlen] = 0; // null terminated
            //printf("newbuff: %s\n", newbuff);
            sz = newsz;
            len = newlen;
            free(buff);
            buff = newbuff;
        } else if (*s >= '0' && *s <= '9') {
            n = n * 10 + (*s) - '0';
        } else {
            if (!buff) {
                sz = 10;
                buff = malloc(sz * sizeof(char));
                //assert(buff);
                len = 0;
            }
            buff[len ++] = *s;
            if (len == sz) {
                sz += 10;
                buff = realloc(buff, sizeof(char));
                //assert(buff);
            }
            buff[len] = 0; // null terminated
        }
        s ++;
    }
    if (!buff) buff = calloc(1, sizeof(char));
    //assert(buff);
    return buff;
}
​
// a very typical yacc grammar:
/*
decoded_string:
      letters
    | pattern
    | decoded_string letters
    | decoded_string pattern
    ;
pattern:
      number '[' decoded_string ']'
    ;
*/


/*
Difficulty:Medium
Total Accepted:33.6K
Total Submissions:81.5K


Companies Google
Related Topics Depth-first Search Stack
Similar Questions 
                
                  
                    Encode String with Shortest Length
*/
