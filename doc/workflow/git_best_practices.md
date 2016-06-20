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


* **features/<github-issue-id>-<branch-name>** - name for branch, that introduces one or few new features
* **fixes/<github-issue-id>-<branch-name>** - name for branch, that applies one or few new bug fixes
* **experiments/<github-issue-id>-<branch-name>** - name for branch, that contains experiments, coding attempts, ideas or any kind of personal stuff
* Use only lower case words and “-” symbol for branch names.

## 2. Developer Workflow



