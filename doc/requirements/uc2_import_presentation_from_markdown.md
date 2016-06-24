# [UC2] Import presentation from Markdown

**Description:** Actor should be able to generate presentation from Github Markdown formatted documents. To do so, he can use application for importing Markdown file into a presentation. 

**Actors:** presentation author, reporter, presentation viewer

**Prerequisites:** application running, no popup dialogs are shown

**Basic Flow:**
 * 1: Actor selects “File” menu from main menu bar.
 * 2: User selects “Import...” menu item from “File” menu.
 * 3: Application shows dialog for opening Markdown file. Only folders, system locations and Markdown files are visible in dialog.
 * 4: Actor selects single markdown file from file system and clicks "Open".
 * 5: Application shows import progress.
 * 6: After import finish, application shows imported presentation. First slide of the presentation is opened in a window.
 

**Alternative Flows:**
 * 4a: User clicks "Cancel".
   * 4a1: Dialog for opening file closes.
   

 * 3a: Application detects that opened document contains unsaved changes
   * 3a1: Popup dialog appears and asks actor whether he wants to save unsaved changes.
     * 3a1a: User chooses to save unsaved changes and application saves edited presentation. Application shows dialog for opening Markdown file right after saving.
     * 3a1b: User chooses not to save any changes. Changes are discarded and application Application shows dialog for opening Markdown file.
     * 3a1c: User chooses to cancel import process - dialog is closed, nothing happens.
  
  
 * 6a: Error occurs during the import process.
   * 6a1: Error message appears with "Ok" button.
   * 6a2: After reading error message, actor press "Ok" button.
   * 6a3: Actor sent back to start screen. 
