<?php
/**
 * @file
 * Isbn form
 */

function isbndb_form($form, &$form_state) {

  drupal_add_css(drupal_get_path('module', 'isbndb') . '/isbndb.css');

  $form['#attached'] = array(
  		'js' => array(drupal_get_path('module', 'isbndb') . '/isbndb.js'),
  );

  global $user;

  if (is_array($user->roles) && in_array('administrator', $user->roles)) {
    $form['base_acces_link'] = array(
      '#type' => 'hidden',
      '#value' => 'http://isbndb.com/api/books.xml?access_key=G9YQHUPG',
      '#id' => 'edit-base-acces-link'		
    );

    $form['acces_link'] = array(
      '#type' => 'textarea',
      '#title' => 'Link',
      '#default_value' => 'http://isbndb.com/api/books.xml?access_key=G9YQHUPG',
      '#disabled' => TRUE,
      '#resizable' => FALSE,
    );
  }
  $form['argument'] = array(
    '#type' => 'select',
    '#title' => 'Argument',
    '#options' => array(
      'isbn' => 'isbn',
      'title' => 'title',
      'combined' => 'combined',
      'full' => 'full',
      'book_id' => 'book_id',
      'person_id' => 'person_id',
      'publisher_id' => 'publisher_id',
      'subject_id' => 'subject_id',
      'dewey_decimal' => 'dewey_decimal',
      'lcc_number' => 'lcc_number'
    ),
    '#description' => '<div id="argument_description" class="fild-description">' . t('Select argument') . '</div>',
    '#attributes' => array('class' => array('float-description')),
    '#required' => TRUE,
    '#ajax' => array(
      'callback' => 'argument_description_function',
      'wrapper' => 'argument_description',
      'method' => 'replace',
      'effect' => 'fade',
      'progress' => array(
        'message' => '',
      ),
    ),
  );
  
  $form['search_data'] = array(
    '#type' => 'textfield',
    '#title' => 'Search data',
    '#maxlength' => 128,
    '#required' => TRUE,
  );
  
  $form['specific_result'] = array(
    '#type' => 'select',
    '#title' => 'Specific result',
    '#options' => array(
      0 => ' - Select - ',
      'details' => 'details',
      'texts' => 'texts',
      'prices' => 'prices',
      'pricehistory' => 'pricehistory',
      'subjects' => 'subjects',
      'marc' => 'marc',
      'authors' => 'authors'
    ),
    '#description' => '<div id="specific_result_description" class="fild-description">' . t('Select type of result') . '</div>',
    '#attributes' => array('class' => array('float-description')),
    '#ajax' => array(
      'callback' => 'specific_result_description_function',
      'wrapper' => 'specific_result_description',
      'method' => 'replace',
      'effect' => 'fade',
      'progress' => array(
        'message' => '',
      ),
    ),
  );
/*$some_html = '<div id="map" onclick="alert(\'ssss\')" class="olMap">main
 <div id="OpenLayers.Map_4_OpenLayers_ViewPort" style="" class="olMapViewport olControlDragPanActive olControlZoomBoxActive olControlPinchZoomActive olControlNavigationActive SpatialMapControlKeyboardDefaultsActive olControlSelectFeatureActive">div1
  <div id="OpenLayers.Map_4_OpenLayers_Container" style="">div2
   <div id="OpenLayers.Layer.WMS_19" style="" dir="ltr" class="olLayerDiv olLayerGrid">div3</div>
   <div id="OpenLayers.Layer.WMS_21" style="" dir="ltr" class="olLayerDiv olLayerGrid">div3</div>
   <div id="OpenLayers.Layer.Vector_24" style="" dir="ltr" class="olLayerDiv">div3
    <svg id="OpenLayers.Layer.Vector_24_svgRoot" style="display: block;" width="664" height="531" viewBox="0 0 664 531">svg4
     <g id="OpenLayers.Layer.Vector_24_root" style="visibility: visible;" transform="">g5
      <g id="OpenLayers.Layer.Vector_24_vroot">
      <image alt="img1div31" id="OpenLayers.Geometry.Point_30" cx="1" cy="530" r="1" preserveAspectRatio="none" x="0" y="0" width="664" height="531" href="/sites/dek.dk/modules/custom/dek_map/maps/region.png" style="" fill="#000000" fill-opacity="1" stroke="blue" stroke-opacity="1" stroke-width="2" stroke-linecap="round" stroke-linejoin="round"/>img g6</g>
      <g id="OpenLayers.Layer.Vector_24_troot"/>g6</g>
   </svg>
  </div>
  <div id="OpenLayers.Layer.Vector_41" style="" dir="ltr" class="olLayerDiv">div3
   <svg id="OpenLayers.Layer.Vector_41_svgRoot" style="display: block;" width="664" height="531" viewBox="0 0 664 531">svg4
    <g id="OpenLayers.Layer.Vector_41_root" style="visibility: visible;" transform="">g5
     <g id="OpenLayers.Layer.Vector_41_vroot"> 
      <image alt="img1div31" id="OpenLayers.Geometry.Point_43" cx="293" cy="351" r="1" preserveAspectRatio="none" x="282" y="323" width="22" height="28" href="/sites/dek.dk/modules/custom/dek_map/includes/img/icon.png" style="opacity: 1" transform="rotate(0 293 351)" fill="#F00" fill-opacity="0.4" stroke="#ee9900" stroke-opacity="1" stroke-width="1" stroke-linecap="round" stroke-linejoin="round" stroke-dasharray="none" pointer-events="visiblePainted" cursor="pointer"/>
      <image alt="img1div32" id="OpenLayers.Geometry.Point_46" cx="264" cy="307" r="1" preserveAspectRatio="none" x="253" y="279" width="22" height="28" href="/sites/dek.dk/modules/custom/dek_map/includes/img/icon.png" style="opacity: 1" transform="rotate(0 264 307)" fill="#F00" fill-opacity="0.4" stroke="#ee9900" stroke-opacity="1" stroke-width="1" stroke-linecap="round" stroke-linejoin="round" stroke-dasharray="none" pointer-events="visiblePainted" cursor="pointer"/>
      <image alt="img1div33" id="OpenLayers.Geometry.Point_49" cx="255" cy="351" r="1" preserveAspectRatio="none" x="244" y="323" width="22" height="28" href="/sites/dek.dk/modules/custom/dek_map/includes/img/icon.png" style="opacity: 1" transform="rotate(0 255 351)" fill="#F00" fill-opacity="0.4" stroke="#ee9900" stroke-opacity="1" stroke-width="1" stroke-linecap="round" stroke-linejoin="round" stroke-dasharray="none" pointer-events="visiblePainted" cursor="pointer"/>
      <image alt="img1div34" id="OpenLayers.Geometry.Point_52" cx="295" cy="291" r="1" preserveAspectRatio="none" x="284" y="263" width="22" height="28" href="/sites/dek.dk/modules/custom/dek_map/includes/img/icon.png" style="opacity: 1" transform="rotate(0 295 291)" fill="#F00" fill-opacity="0.4" stroke="#ee9900" stroke-opacity="1" stroke-width="1" stroke-linecap="round" stroke-linejoin="round" stroke-dasharray="none" pointer-events="visiblePainted" cursor="pointer"/>
      <image alt="img1div35" id="OpenLayers.Geometry.Point_55" cx="261" cy="331" r="1" preserveAspectRatio="none" x="250" y="303" width="22" height="28" href="/sites/dek.dk/modules/custom/dek_map/includes/img/icon.png" style="opacity: 1" transform="rotate(0 261 331)" fill="#F00" fill-opacity="0.4" stroke="#ee9900" stroke-opacity="1" stroke-width="1" stroke-linecap="round" stroke-linejoin="round" stroke-dasharray="none" pointer-events="visiblePainted" cursor="pointer"/>
      <image alt="img1div36" id="OpenLayers.Geometry.Point_58" cx="277" cy="337" r="1" preserveAspectRatio="none" x="266" y="309" width="22" height="28" href="/sites/dek.dk/modules/custom/dek_map/includes/img/icon.png" style="opacity: 1" transform="rotate(0 277 337)" fill="#F00" fill-opacity="0.4" stroke="#ee9900" stroke-opacity="1" stroke-width="1" stroke-linecap="round" stroke-linejoin="round" stroke-dasharray="none" pointer-events="visiblePainted" cursor="pointer"/>
      <image alt="img1div37" id="OpenLayers.Geometry.Point_61" cx="465" cy="371" r="1" preserveAspectRatio="none" x="454" y="343" width="22" height="28" href="/sites/dek.dk/modules/custom/dek_map/includes/img/icon.png" style="opacity: 1" transform="rotate(0 465 371)" fill="#F00" fill-opacity="0.4" stroke="#ee9900" stroke-opacity="1" stroke-width="1" stroke-linecap="round" stroke-linejoin="round" stroke-dasharray="none" pointer-events="visiblePainted" cursor="pointer"/>
      <image alt="img1div38" id="OpenLayers.Geometry.Point_64" cx="475" cy="351" r="1" preserveAspectRatio="none" x="464" y="323" width="22" height="28" href="/sites/dek.dk/modules/custom/dek_map/includes/img/icon.png" style="opacity: 1" transform="rotate(0 475 351)" fill="#F00" fill-opacity="0.4" stroke="#ee9900" stroke-opacity="1" stroke-width="1" stroke-linecap="round" stroke-linejoin="round" stroke-dasharray="none" pointer-events="visiblePainted" cursor="pointer"/>
      <image alt="img1div39" id="OpenLayers.Geometry.Point_67" cx="463" cy="416" r="1" preserveAspectRatio="none" x="452" y="388" width="22" height="28" href="/sites/dek.dk/modules/custom/dek_map/includes/img/icon.png" style="opacity: 1" transform="rotate(0 463 416)" fill="#F00" fill-opacity="0.4" stroke="#ee9900" stroke-opacity="1" stroke-width="1" stroke-linecap="round" stroke-linejoin="round" stroke-dasharray="none" pointer-events="visiblePainted" cursor="pointer"/>
      <image alt="img1div310" id="OpenLayers.Geometry.Point_70" cx="485" cy="380" r="1" preserveAspectRatio="none" x="474" y="352" width="22" height="28" href="/sites/dek.dk/modules/custom/dek_map/includes/img/icon.png" style="opacity: 1" transform="rotate(0 485 380)" fill="#F00" fill-opacity="0.4" stroke="#ee9900" stroke-opacity="1" stroke-width="1" stroke-linecap="round" stroke-linejoin="round" stroke-dasharray="none" pointer-events="visiblePainted" cursor="pointer"/>
      <image alt="img1div311" id="OpenLayers.Geometry.Point_73" cx="477" cy="392" r="1" preserveAspectRatio="none" x="466" y="364" width="22" height="28" href="/sites/dek.dk/modules/custom/dek_map/includes/img/icon.png" style="opacity: 1" transform="rotate(0 477 392)" fill="#F00" fill-opacity="0.4" stroke="#ee9900" stroke-opacity="1" stroke-width="1" stroke-linecap="round" stroke-linejoin="round" stroke-dasharray="none" pointer-events="visiblePainted" cursor="pointer"/>
     </g>
     <g id="OpenLayers.Layer.Vector_41_troot"/>g</g>
    </svg>
   </div>
  </div>
  <div id="OpenLayers.Control.SelectFeature_76" style="" class="olControlSelectFeature olControlNoSelect" unselectable="on"></div>
 </div>
</div>';  
  $form['test'] = array(
  		'#type' => 'item',
  		//'#title' => 'Link',
  		'#markup' => $some_html,
  		//'#disabled' => TRUE,
  		//'#resizable' => FALSE,
  );
*/
  $form['submit_button'] = array(
    '#type' => 'submit',
    '#value' => t('View data'),
    '#suffix' => '<hr><br><div id="isbn_data"></div>',
    '#ajax' => array(
      'callback' => 'isbn_data_function',
      'wrapper' => 'isbn_data',
      'method' => 'replace',
      'effect' => 'fade',
      'progress' => array(
        'message' => '... loading',
      ),
    ),
  );

  return $form;
}

function argument_description_function($form, &$form_state) {
  $description_argument_array = array(
    'isbn' => t('Search on ISBN, value is set the ISBN you are interested in.'),
    'title' => t('Keywords search on book title, long title, and latin-ized title for unicode titles.'),
    'combined' => t('Search index that combines titles, authors, and publisher name.'),
    'full' => t('Search index that includes titles, authors, publisher name, summary, notes, awards information, etc'),
    'book_id' => t('Retrieving book data by ISBNdb.com\'s book ID.'),
    'person_id' => t('Retrieves a list of books by the given author, editor, etc.'),
    'publisher_id' => t('Retrieves a list of books by the given publisher ID.'),
    'subject_id' => t('Retrieves a list of books on the given subject.'),
    'dewey_decimal' => t('Retrieves a list of books by the given Dewey Decimal Classification number.'),
    'lcc_number' => t('Retrieves a list of books by the given Library of Congress Classification number.')
  );

  $description_arg_data = '<div id="argument_description" class="fild-description">' . t('Select argument') . '</div>';
  if (in_array($form_state['values']['argument'], array_keys($description_argument_array))) {
    $description_arg_data = '<div id="argument_description" class="fild-description">' .
      $description_argument_array[$form_state['values']['argument']] . '</div>';
  }
  return $description_arg_data;
}

function specific_result_description_function($form, &$form_state) {
  $description_result_array = array(
    0 => t('Select type of result'),
    'details' => t('Show more details about books - LCC and Dewey decimal classification, release data, etc.'),
    'texts' => t('Show textual blocks for the book - notes, summary, awards information, related URLs, etc.'),
    'prices' => t('Show current prices for the found books.'),
    'pricehistory' => t('The same as \'prices\', but the results are not limited to most current prices. May take more time for load data.'),
    'subjects' => t('This argument tells ISBNdb.com server to return a list of subjects for each book found.'),
    'marc' => t('This argument tells ISBNdb.com server to return a list of URLs to the book\'s MARC records if it has any.'),
    'authors' => t('This argument tells ISBNdb.com server to return a list of authors, editors, etc for each book found.')
  );

  $description_result_data = '<div id="specific_result_description" class="fild-description">' .
    t('Select type of result') . '</div>';
  if (in_array($form_state['values']['specific_result'], array_keys($description_result_array))) {
    $description_result_data = '<div id="specific_result_description" class="fild-description">' .
      $description_result_array[$form_state['values']['specific_result']] . '</div>';
  }
  return $description_result_data;
}

function isbn_data_function($form, &$form_state) {
  $rows = array();
  $header = array();
  if ($form_state['values']['argument'] && $form_state['values']['search_data']) {
    $link = 'http://isbndb.com/api/books.xml?access_key=G9YQHUPG&index1=' . $form_state['values']['argument'];
    $link .= '&value1=' . str_replace(' ', '+', $form_state['values']['search_data']);
    $link .= $form_state['values']['specific_result'] ? ('&results=' . $form_state['values']['specific_result']) : '';

    $xml = simplexml_load_file($link);

    $result = $xml->xpath("/ISBNdb/BookList/BookData");

    foreach ($result as $item) {
      $row = array();
      $header = array();
      foreach ($item as $key => $val) {
        if (count($val->attributes()) > 0 && $key=='Details') {
          foreach ($val->attributes() as $key1 => $val1) {
            $header[] = $key1;
            $row[] = (string)$val1;
          }
        }
        elseif ($key=='Prices' || $key=='MARCRecords') {
          $header[] = $key;
          $row_data = array();
          foreach ($val as $subkey => $subvalue) {
            if (count($subvalue->attributes()) > 0) {
              $row_subdata = array();
              foreach ($subvalue->attributes() as $subkey1 => $subvalue1) {
                if ((string)$subvalue1!='') {
                  $row_subdata[] = '<b>' . $subkey1 . '</b> : ' . (string)$subvalue1;
                }
              }
            }
            $row_data[] = implode(', ', $row_subdata);
          }
          $row[] = implode('<hr>', $row_data);
        }
        elseif ($key=='Subjects' || $key=='Authors') {
          $header[] = $key;
          $row_datas = array();
          foreach ($val as $ssubkey => $ssubval) {
            $row_datas[] = (string)$ssubval;
          }
          $row[] = implode('<br>', $row_datas);
        }
        else {
          $header[] = $key;
          $row[] = (string)$val;
        }
      }
      $rows[] = $row;
    }
  }
  $table = theme('table', array(
      'header' => $header,
      'rows' => $rows));

  if ($result) {
    $output = '<div id="isbn_data">' . render($table) . '</div>';
  }
  else {
    $output = '<div id="isbn_data">' . t('No results found') . '</div>';
  }
  return $output;
}




