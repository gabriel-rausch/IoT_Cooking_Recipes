# WebApp Deployment

Same as previous example: WebApp Controls ESP

This time the website ressources are handled within a grund task runner. Thus, you can design and develop your webapp in a regular environment without restrictions. Here the folder ``webapp`` serves all source files of the web application. As soon as the build task is fired the webapp is packed together in the final webapp.h file (the intermediate processed files of this procedure can be found in /webapp/dist).

1. First install all npm dependencies that are mentioned in package.json via ``npm install`` within this folder
2. Modify something in the webapp (styles, script or the HTML part)
3. Run ``grunt build`` to perform the webapp deployment process
4. After grunt has build the web project the final file ``webapp-index.h`` should be up-to-date
5. Now you can compile and upload the ESP sketch to the MCU

This example covers the following:
- Images are embedded via base64 in the stylesheet
- All ressources are stripped, unneccessary whitespace is removed (uglified)
- All script and style resourrces are embedded within the html file
- The final html is wrapped as an c++ char in webapp-index.h

Follow the Gruntfile.js from top to bottom to get an understanding about the details of this procedure.

[Demo Video](demo_webapp_deployment.mp4)

### Further Readings:

[Grunt](https://gruntjs.com) or [Gulp](https://gulpjs.com) are great tools to automate stuff. Reade more about these toolkits on their website.