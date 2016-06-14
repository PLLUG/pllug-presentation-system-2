# [UC1] Quitting application using main menu

**Description:** Actor could quit application using application menu or keyboard shortcut. If during the quit process unsaved data will be found - user should see a message. 

**Actors:** presentation author, reporter, presentation viewer

**Prerequisites:** application running, no popup dialogs are shown

**Basic Flow:**
 * 1: Actor selects “File” menu from main menu bar.
 * 2: User selects “Quit” menu item from “File” menu.
 * 3: Application shuts down.
 
**Alternative Flows:**
 *
 * 3a: There is some unsaved data in the current edited document.
   * 3a1: Popup dialog appears and asks actor whether he wants to save unsaved changes.
     * 3a1a: User chooses to save unsaved changes and application saves edited presentation. Application quits right after saving.
     * 3a1b: User chooses not to save any changes. Changes are discarded and application quits immediately.
     * 3a1c: User chooses to cancel quit process - dialog are closed, nothing happens.
 