<?php

/**
 * @file
 * Provides resources for services.
 */

/**
 * Implements hook_services_resources().
 */
function lessons_api_services_resources() {
  return array(
    'lessons' => array(
      'retrieve' => array(
        'help' => 'Retrieves a lesson',
        'file' => array(
          'type' => 'inc',
          'module' => 'lessons_api',
          'name' => 'lessons_api.resource',
        ),
        'callback' => '_lesson_service_retrieve',
        'access callback' => '_lesson_service_access',
        'access arguments' => array('view'),
        'access arguments append' => TRUE,
        'args' => array(
          array(
            'name' => 'nid',
            'type' => 'int',
            'description' => 'The id of the lesson to retrieve',
            'source' => array('path' => '0'),
            'optional' => FALSE,
          ),
        ),
      ),
      'create' => array(
        'help' => 'Creates a lesson',
        'file' => array(
          'type' => 'inc',
          'module' => 'lessons_api',
          'name' => 'lessons_api.resource',
        ),
        'callback' => '_lesson_service_create',
        'access arguments' => array('lesson service create'),
        'access arguments append' => FALSE,
        'args' => array(
          array(
            'name' => 'data',
            'type' => 'lessons',
            'description' => 'The lesson object',
            'source' => array('data'),
            'optional' => FALSE,
          ),
        ),
      ),
      'update' => array(
        'help' => 'Updates a lesson',
        'file' => array(
          'type' => 'inc',
          'module' => 'lessons_api',
          'name' => 'lessons_api.resource',
        ),
        'callback' => '_lesson_service_update',
        'access callback' => '_lesson_service_access',
        'access arguments' => array('update'),
        'access arguments append' => TRUE,
        'args' => array(
          array(
            'name' => 'nid',
            'type' => 'int',
            'description' => 'The id of the lesson to update',
            'source' => array('path' => '0'),
            'optional' => FALSE,
          ),
          array(
            'name' => 'data',
            'type' => 'lessons',
            'description' => 'The note lesson object',
            'source' => array('data'),
            'optional' => FALSE,
          ),
        ),
      ),
      'delete' => array(
        'help' => 'Deletes a lesson',
        'file' => array(
          'type' => 'inc',
          'module' => 'lessons_api',
          'name' => 'lessons_api.resource',
        ),
        'callback' => '_lesson_service_delete',
        'access callback' => '_lesson_service_access',
        'access arguments' => array('delete'),
        'access arguments append' => TRUE,
        'args' => array(
          array(
            'name' => 'nid',
            'type' => 'int',
            'description' => 'The id of the lesson to delete',
            'source' => array('path' => '0'),
            'optional' => FALSE,
          ),
        ),
      ),
      'index' => array(
        'help' => 'Retrieves a listing of lessons',
        'file' => array(
          'type' => 'inc',
          'module' => 'lessons_api',
          'name' => 'lessons_api.resource',
        ),
        'callback' => '_lesson_service_index',
        'access callback' => 'user_access',
        'access arguments' => array('access content'),
        'access arguments append' => FALSE,
        'args' => array(
          array(
            'name' => 'page',
            'type' => 'int',
            'description' => '',
            'source' => array(
              'params' => 'page',
            ),
            'optional' => TRUE,
            'default value' => 0,
          ),
          array(
            'name' => 'parameters',
            'type' => 'array',
            'description' => '',
            'source' => 'param',
            'optional' => TRUE,
            'default value' => array(),
          ),
        ),
      ),
    ),
  );
}
