<?php

/**
 * @file
 * Contains Drupal\tracdelight\Entity\Form\ProductForm.
 */

namespace Drupal\tracdelight\Entity\Form;

use Drupal\Core\Entity\ContentEntityForm;
use Drupal\Core\Form\FormStateInterface;
use Drupal\Core\Language\Language;

/**
 * Form controller for Product edit forms.
 *
 * @ingroup tracdelight
 */
class ProductForm extends ContentEntityForm {
  /**
   * {@inheritdoc}
   */
  public function buildForm(array $form, FormStateInterface $form_state) {
    /* @var $entity \Drupal\tracdelight\Entity\Product */
    $form = parent::buildForm($form, $form_state);
    $entity = $this->entity;

    $form['langcode'] = array(
      '#title' => $this->t('Language'),
      '#type' => 'language_select',
      '#default_value' => $entity->getUntranslated()->language()->getId(),
      '#languages' => Language::STATE_ALL,
    );

    return $form;
  }

  /**
   * {@inheritdoc}
   */
  public function submit(array $form, FormStateInterface $form_state) {
    // Build the entity object from the submitted values.
    $entity = parent::submit($form, $form_state);

    return $entity;
  }

  /**
   * {@inheritdoc}
   */
  public function save(array $form, FormStateInterface $form_state) {
    $entity = $this->entity;
    $status = $entity->save();

    switch ($status) {
      case SAVED_NEW:
        drupal_set_message($this->t('Created the %label Product.', [
          '%label' => $entity->label(),
        ]));
        break;

      default:
        drupal_set_message($this->t('Saved the %label Product.', [
          '%label' => $entity->label(),
        ]));
    }
    $form_state->setRedirect('entity.product.edit_form', ['product' => $entity->id()]);
  }

}
