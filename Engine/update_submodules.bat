@echo off
WARNING: This will pull the main repo of each repository. Please submit your changes to the individual repositories before continuing.
pause

cd EclipseChat
git stash
git pull origin main
cd ../EclipseDebugging
git stash
git pull origin main
git stash
cd ../EclipseGraphics
git stash
git pull origin main
cd ../EclipseGui
git stash
git pull origin main
cd ../EclipseNetworking
git stash
git pull origin main
cd ../EclipseScripting
git stash
git pull origin main
pause