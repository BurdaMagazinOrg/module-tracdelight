<?php

class TracdelightProductUIController extends EntityDefaultUIController {

}

/**
 * Task Form.
 */
function tracdelight_product_form($form, &$form_state, $tracdelight_product) {
  $form_state['tracdelight_product'] = $tracdelight_product;

  $form['ein'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => t('EIN'),
    '#default_value' => $tracdelight_product->ein,
  );

  return $form;
}
