//
//  AppDelegate.m
//  LaMoKeyHelper
//
//  Created by Tuyen on 2/1/19.
//  Copyright © 2019 Tuyen Mai. All rights reserved.
//

#import "AppDelegate.h"
#import <libproc.h>

@interface AppDelegate ()

@property (weak) IBOutlet NSWindow *window;
@end

@implementation AppDelegate

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification {
    uid_t currentUID = getuid();
    bool mainAppRunning = false;
    NSArray* runningApps = [[NSWorkspace sharedWorkspace] runningApplications];
    for (NSRunningApplication* app in runningApps) {
        if ([[app bundleIdentifier] isEqualToString:@"com.tuyenmai.lamokey"]) {
            pid_t pid = [app processIdentifier];
            struct proc_bsdinfo procInfo;
            if (proc_pidinfo(pid, PROC_PIDTBSDINFO, 0, &procInfo, PROC_PIDTBSDINFO_SIZE) > 0) {
                if (procInfo.pbi_uid == currentUID) {
                    mainAppRunning = true;
                    break;
                }
            }
        }
    }
    if (!mainAppRunning) {
        NSString* path = [[NSBundle mainBundle] bundlePath];
        for (int i = 0; i < 4; i++)
            path = [path stringByDeletingLastPathComponent];
        [[NSWorkspace sharedWorkspace] launchApplication:path];
    }
}


- (void)applicationWillTerminate:(NSNotification *)aNotification {
    // Insert code here to tear down your application
}


@end
