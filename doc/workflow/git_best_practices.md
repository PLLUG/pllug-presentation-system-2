# Git Best Practices

## 1. Branching Model

### 1.1 Main Branches

* **master** - always contains production quality program code.
  * Properly tested and approved code release.
  * Every commit shold be tagged as a new version.
  * Direct commits of any changes into master are forbidden.
  * master branch should be protected from direct commits and opened for merging only for responsible for release developers.


* **development** - contains development version of code with all latest fieatures implemented
  * Direct commits of any changes into development are forbidden.
  * development branch should be protected from direct commits.
  * Allowed merge requests of personal feature branches to development branch.
  * When code in branch has enough features and ready for release - code should be merged into master branch


### 1.2 Name Convension for Custom Branches


* features/(github-issue-id)-(branch-name) - name for branch, that introduces one or few new features
* fixes/(github-issue-id)-(branch-name) - name for branch, that applies one or few new bug fixes
* experiments/(github-issue-id)-(branch-name) - name for branch, that contains experiments, coding attempts, ideas or any kind of personal stuff
* Use only lower case words and “-” symbol for branch names.


## 2. Developer Workflow

1. Select Github issue and move it to "in progress" state.
2. Create branch from **development** for working on the issue. Example: features/22-branching-model
3. Work on issue, commit code.
4. Push your working branch to remote.
5. Create pull request to **development** branch.
6. Make sure that all build tests are passing. Fix errors/warnings if any.
7. Fix all issues according to code review comments and push fixes to remote. Again check for all build tests passing.
8. Wait for merge approval then merge branch into development. 
9. Remove your branch.

## 3. Git Best Practices

### Git.1: Create separate feature/fix branch for each task.
Make only necessary changes to implement some feature or make bugfix, and keep them in separate branch. That will allow to simplify code review and keep track of all changes.

***

### Git.2: Name of feature branch should be informative and contain task ID.
Create a name that allow everyone to easily recognize what kind of changes it contains. Task ID will allow to keep connection to certain ticket. Also feature- and fix- prefixes for branches that contain feature implementation or bugfix could be a good practice.

**Examples (Good):**

`feature-21-CommandLinedParser`

**Examples (Bad):**

`version-1 `

***

### Git.3: Commit comment should be informative and clearly describe waht was changed.
You should be able to look at commit description and understand changes in general without looking into diff. 

**Examples (Good):**

`.gitignore updated to exclude files generated for C++ project`

**Examples (Bad):**

` small fixes `

For more bad examples look here: http://whatthecommit.com/ (F5 for new one)
### Git.4: Commits often.
You should commit your changes every time, when you completed some small logical part of your task. 

***



