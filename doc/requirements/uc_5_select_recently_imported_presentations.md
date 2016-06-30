# [UC5] Select recently imported presentations

**Description:** Actor can import again presentations that was recently imported. For convenience of the actor all recently imported presentation are displayed on start screen after application launch. 

**Actors:** presentation author, reporter, presentation viewer

**Prerequisites:** no popup dialogs are shown, no presentations are opened

**Basic Flow:**
 * 1: Actor starts application. 
 * 2: Application launched and start screen is shown. Scrollable list of recently imported presentations is shown (up to 20 items). Actor can see thumbnail for the first slide of the presentation and imported document name.
 * 3: User clicks on one of the items. 
 * 4: Import of the selected presentation is started. Application shows import progress.
 * 5: After import finish, application shows imported presentation. First slide of the presentation is opened in a window.


**Alternative Flows:**
 * 2a: No presentations was imported previously.
   * 2a1: No recent items are displayed on the start screen.


 * 5a: Error occurs during the import process.
   * 5a1: Error message appears with "Ok" button.
   * 5a2: After reading error message, actor press "Ok" button.
   * 5a3: Actor sent back to start screen. 
