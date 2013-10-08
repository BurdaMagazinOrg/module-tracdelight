<?php
class TracdelightProductUIController extends EntityDefaultUIController {
}

function tracdelight_product_add() {
  $tracdelight_product = (object) array(
    'ein' => '',
    'detailpageurl' => '',
    'type' => 'tracdelight_product',
  );

  return drupal_get_form('tracdelight_product_form', $tracdelight_product);
}

function tracdelight_product_add_form_submit($form, &$form_state) {

  $form_state['values']['is_new'] = isset($form_state['tracdelight_product']->is_new) ? $form_state['tracdelight_product']->is_new : FALSE;

  $tracdelight_product_submission = (object) $form_state['values'];
  field_attach_submit('tracdelight_product', $tracdelight_product_submission, $form, $form_state);
  $tracdelight_product = tracdelight_product_save($tracdelight_product_submission);

  $form_state['redirect'] = "tracdelight_product/$tracdelight_product->id";
}

function tracdelight_product_form($form, &$form_state, $tracdelight_product) {

  $form_state['tracdelight_product'] = $tracdelight_product;

  $form['ein'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => t('EIN'),
    '#default_value' => isset($tracdelight_product->ein) ? $tracdelight_product->ein : NULL,
    '#disabled' => !(isset($tracdelight_product->is_new) && $tracdelight_product->is_new),
  );

  $form['sku'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => t('SKU'),
    '#default_value' => isset($tracdelight_product->sku) ? $tracdelight_product->sku : NULL,
  );

  $form['detailpageurl'] = array(
    '#type' => 'textfield',
    '#title' => t('Page URL'),
    '#default_value' => isset($tracdelight_product->detailpageurl) ? $tracdelight_product->detailpageurl : NULL,
    '#required' => TRUE,
  );

  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#default_value' => isset($tracdelight_product->title) ? $tracdelight_product->title : NULL,
    '#required' => TRUE,
  );

  $form['manufacturer'] = array(
    '#type' => 'textfield',
    '#title' => t('Manufacturer'),
    '#default_value' => isset($tracdelight_product->manufacturer) ? $tracdelight_product->manufacturer : NULL,
  );

  $form['brand'] = array(
    '#type' => 'textfield',
    '#title' => t('Brand'),
    '#default_value' => isset($tracdelight_product->brand) ? $tracdelight_product->brand : NULL,
    '#required' => TRUE,
  );

  $form['description'] = array(
    '#type' => 'textfield',
    '#title' => t('Description'),
    '#default_value' => isset($tracdelight_product->description) ? $tracdelight_product->description : NULL,
    '#required' => TRUE,
  );

  $form['shippingcosts'] = array(
    '#type' => 'textfield',
    '#title' => t('Shipping costs'),
    '#default_value' => isset($tracdelight_product->shippingcosts) ? $tracdelight_product->shippingcosts : NULL,
  );

  $form['deliverytime'] = array(
    '#type' => 'textfield',
    '#title' => t('Delivery time'),
    '#default_value' => isset($tracdelight_product->deliverytime) ? $tracdelight_product->deliverytime : NULL,
  );

  $form['formattedprice'] = array(
    '#type' => 'textfield',
    '#title' => t('Price'),
    '#default_value' => isset($tracdelight_product->formattedprice) ? $tracdelight_product->formattedprice : NULL,
    '#required' => TRUE,
  );

  $form['shop'] = array(
    '#type' => 'textfield',
    '#title' => t('Shopname'),
    '#default_value' => isset($tracdelight_product->shop) ? $tracdelight_product->shop : NULL,
  );

  $form['active'] = array(
    '#type' => 'radios',
    '#title' => t('Active'),
    '#default_value' => isset($tracdelight_product->active) ? $tracdelight_product->active : 1,
    '#options' => array(0 => t('Closed'), 1 => t('Active')),
    '#required' => TRUE,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#submit' => array('tracdelight_product_add_form_submit'),
    '#weight' => 100,
  );

  field_attach_form('tracdelight_product', $tracdelight_product, $form, $form_state);

  return $form;
}

function tracdelight_product_admin_page() {
  $content = array();
  $content[] = array(
    '#type' => 'item',
    '#markup' => t('Administration page for tracdelight products.'),
  );

  return $content;
}

/**
 *
 * @param $form
 * @param $form_state
 *
 * @return mixed
 */
function tracdelight_admin($form, &$form_state) {
  $form = array();

  $form['tracdelight_access_key'] = array(
    '#type' => 'textfield',
    '#title' => t('tracdelight AccessKey'),
    '#default_value' => variable_get('tracdelight_access_key', ''),
    '#size' => 32,
    '#maxlength' => 32,
    '#required' => TRUE,
  );


  return system_settings_form($form);
}

