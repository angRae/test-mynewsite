<?php
/**
 * @file
 * online_books_feature.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function online_books_feature_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Scientific publications',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => '0',
    'uuid' => '09838a1c-5151-6d94-a13d-e1ba30f920bc',
    'vocabulary_machine_name' => 'books_category',
  );
  $terms[] = array(
    'name' => 'Sci-Fi',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => '0',
    'uuid' => '099240a9-4712-63f4-e9b8-d629552cfc03',
    'vocabulary_machine_name' => 'books_category',
  );
  $terms[] = array(
    'name' => 'Fiction',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => '0',
    'uuid' => '11e6d5c3-94cb-95b4-255d-6a0f80387b30',
    'vocabulary_machine_name' => 'books_category',
  );
  $terms[] = array(
    'name' => 'Other',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => '0',
    'uuid' => '54062490-4648-ea64-f172-2ea2e6ba89ad',
    'vocabulary_machine_name' => 'books_category',
  );
  return $terms;
}
