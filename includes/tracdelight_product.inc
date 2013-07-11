<?php

class TracdelightProduct extends Entity {

  public function defaultLabel() {
    return isset($this->ein) ? $this->ein : NULL;
  }
}





function tracdelight_product_uri($tracdelight_product) {
  return array(
    'path' => 'tracdelight_product/' . $tracdelight_product->ein,
  );
}


function tracdelight_product_load($ein = NULL, $reset = FALSE) {
  $eins = (isset ($ein) ? array($ein) : array());
  $tracdelight_product = tracdelight_product_load_multiple($eins, $reset);
  return $tracdelight_product ? reset($tracdelight_product) : FALSE;
}

function tracdelight_product_load_multiple($eins = array(), $conditions = array(), $reset = FALSE) {
  return entity_load('tracdelight_product', $eins, $conditions, $reset);
}

function tracdelight_product_save(&$tracdelight_product) {
  return entity_get_controller('tracdelight_product')->save($tracdelight_product);
}

function tracdelight_product_page_view($tracdelight_product, $view_mode = 'full') {
  $tracdelight_product->content = array();

  // Build fields content.
  field_attach_prepare_view('tracdelight_product', array($tracdelight_product->ein => $tracdelight_product), $view_mode);
  entity_prepare_view('tracdelight_product', array($tracdelight_product->ein => $tracdelight_product));
  $tracdelight_product->content += field_attach_view('tracdelight_product', $tracdelight_product, $view_mode);

  return $tracdelight_product->content;
}

