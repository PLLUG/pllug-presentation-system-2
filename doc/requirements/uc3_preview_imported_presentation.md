# [UC3] Preview imported presentation

**Description:** After successful import of presentation from Markdown document (see UC2), actor should be able preview imported slides and navigate through the presentation. All slides displayed in **Slides Pane**. User could preview any slide by selecting it in the **Slides Pane**.

**Actors:** presentation author, reporter, presentation viewer

**Prerequisites:** application running, no popup dialogs are shown, presentation successfully imported

**Basic Flow:**
 * 1: Actor sees one slide of the presentation. No more panes displayed.
 * 2: Actor presses **Slides Pane** button.
 * 3: Application shows **Slides Pane**. Pane displays ordered list of thumbnails of all slides in the presentation. Slides displayed in the order they were imported from the document. **Slides Pane** is scrollable.
 * 4: User scrolls to slide he wants to preview.
 * 5: User selects slide.
 * 6: Application shows selected slide.
 * 7: Application hides **Slides Pane**
 

**Alternative Flows:**
 * 4a: User clicks on area outside **Slides Pane**.
   * 4a1: Application hides **Slides Pane**.
