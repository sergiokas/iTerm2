//
//  iTermTabBarControlView.h
//  iTerm
//
//  Created by George Nachman on 5/29/14.
//
//

#import "PSMTabBarControl.h"

// NOTE: The delegate should nil out of itermTabBarDelegate when it gets dealloced; we may live on because of delayed performs.
@protocol iTermTabBarControlViewDelegate

- (BOOL)iTermTabBarShouldFlashAutomatically;
- (void)iTermTabBarWillBeginFlash;
- (void)iTermTabBarDidFinishFlash;

@end

// A customized verison of PSMTabBarControl.
@interface iTermTabBarControlView : PSMTabBarControl

@property(nonatomic, assign) id<iTermTabBarControlViewDelegate> itermTabBarDelegate;

// Set to yes when cmd pressed, no when released. We take care of the timing.
@property(nonatomic, assign) BOOL cmdPressed;

// Call this when the result of iTermTabBarShouldFlash would change.
- (void)updateFlashing;

// Indicates if the tab bar is currently flashing.
- (BOOL)flashing;

// Start or stop flashing. We take care of fading.
- (void)setFlashing:(BOOL)flashing;

@end
