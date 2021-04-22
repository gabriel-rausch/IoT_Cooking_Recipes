# WebApp Offline Support

There are two main concepts you need to invest to create an offline webapp on the esp:

1. Client issue: You need to setup a **service worker** that stores all relevant resources in the client browser cache (in this example just the index.html)
2. Server / ESP issue: Service worker only are available via HTTPS, so you need to set up a https web server on the esp. In this example I use a third-party web server that already offers HTTPS and provides self-signed certificates.

There are some issues where you can continue this study:
- My ESP needs quite a lot of time to create the certificate and start the https server. Perhaps the library is not perfect and there are better approaches / libs. I chould also imagine that the current approach is pretty power consuming, so the idea is to improve this part to protect more resources and save battery.
- The self-signed certificate is easy to use in development (and for our prototyping purpose it's good enough), but the browser shows a warning to the user (in my demo video this in to visible due to the reason that I already accepted this self-signed certificate before). Perhaps somebody of you MIB guys have some smart ideas in here :-)

[Demo Video](demo_webapp_offline.mp4)

### Further Readings:

A simple example on how to use [Service Worker's offline capacities](https://paul.kinlan.me/de/offline-fallback-page-with-service-worker/)

HTTPS Server Library that is used here: [ESP32 HTTPS Server](https://github.com/fhessel/esp32_https_server)


### Alternative approachces
For the sake of completeness we already discussed some other ideas on how to provide "offline" data to the user: simple static files, such as PDFs or images, users can store on their mobile device might be an appropriate solution for you use-case, too.