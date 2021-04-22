/**
 * This is the config file for Grunt task runner
 * 
 * Read this file from to top bottom to get a better 
 * understand of the details of this procedure
 * 
 */

'use strict';

module.exports = function (grunt) {
    grunt.loadNpmTasks('grunt-contrib-copy');
    grunt.loadNpmTasks('grunt-data-uri');
    grunt.loadNpmTasks('grunt-embed');
    grunt.loadNpmTasks('grunt-contrib-htmlmin');
    grunt.loadNpmTasks('grunt-contrib-concat');

    grunt.initConfig({
        copy: {
            main: {
                files: [
                    { src: ['./webapp/index.html'], dest: './webapp/dest/index.html' },
                    { expand: true, flatten: true, src: ['./webapp/js/**'], dest: './webapp/dest/js', filter: 'isFile' },
                    { expand: true, flatten: true, src: ['./webapp/images/**'], dest: './webapp/dest/images', filter: 'isFile' },
                ],
            },
        },
        dataUri: {
            dist: {
                src: ['./webapp/css/*.css'],
                dest: './webapp/dest/css/',
                options: {
                    target: ['./webapp/images/*.*'],
                    fixDirLevel: true

                }
            }
        },
        embed: {
            options: {
                threshold: '1000KB'
            },
            dist: {
                files: {
                    './webapp/dest/index.html': './webapp/dest/index.html'
                }
            }
        },
        htmlmin: {
            dist: {
                options: {
                    minifyCSS: true,
                    removeComments: true,
                    collapseWhitespace: true
                },
                files: {
                    './webapp/dest/index-min.html': './webapp/dest/index.html',
                }
            }
        },
        concat: {
            options: {
            separator: '',
            },
            dist: {
            src: ['./webapp/assets/cpp-chart-start', './webapp/dest/index-min.html', './webapp/assets/cpp-chart-end'],
            dest: './include/webapp-index.h',
            },
        },

    });

    grunt.registerTask('build', ['copy', 'dataUri', 'embed', 'htmlmin', 'concat']);
};
