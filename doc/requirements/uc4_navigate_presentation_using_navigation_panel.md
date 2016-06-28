# [UC4] Navigate presentation using navigation panel

**Description:** After successful import of presentation from Markdown document (see UC2), actor could use **Navigation Panel** to navigate through presentation. 

**Actors:** presentation author, reporter, presentation viewer

**Prerequisites:** application running, no popup dialogs are shown, presentation successfully imported

**Basic Flow:**
 * 1: Actor sees one slide of the presentation. Actor also sees navigation panel that is displayed by the application. Navigation panel contains "Forward" and "Back" buttons. It also displays total numbers of slides in presentation and current slide number. 
 * 2: Actor uses navigation panel to preview another slide. Some number of slides before the current slide and some number of slides after the current is present.
   * 2a1: User clicks "Forward" button.
     * 2a2: Application shows next presentation slide.
     * 2a3: Application increases current slide number and "Forward" button state. 
   * 2b1: User clicks "Back" button.
     * 2a2: Application shows previous presentation slide.
     * 2a3: Application decreases current slide number and "Forward" button state. 


**Alternative Flows:**
 * 2b: Current slide is the last slide in the presentation.
   * 4b1: Application shows "Forward" button disabled. Actor unable to switch to next slide.


 * 2c: Current slide is the first slide in the presentation.
   * 4c1: Application shows "Back" button disabled. Actor unable to switch to previous slide.


 * 2d: Current slide is the first and the last slide in the presentation at the same time.
   * 4d1: Application shows both buttons ("Back" and "Forward" buttons) disabled. Actor unable to switch to previous or to next slide.
