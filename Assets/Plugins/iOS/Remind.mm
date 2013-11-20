#import <Foundation/Foundation.h>
#import "RemindClass.h"
extern "C"{
    void remind_() {
        [RemindClass check];
    }
}
