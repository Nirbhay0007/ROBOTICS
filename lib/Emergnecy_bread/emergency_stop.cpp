#include "emergency_stop.h"

#define   EM_PIN  A0

int emergency_break()
{         
          int rescue = -1;

          int em_ir_value = digitalRead(EM_PIN);
          if(em_ir_value == LOW )
          {
                    rescue = 0;
                    
                    
          }
          
          return rescue;
}