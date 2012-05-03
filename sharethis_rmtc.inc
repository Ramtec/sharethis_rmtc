<?php 

/**
 * @file
 * Form builder for fbwall configuration page
 */

/**
 * fbwall Form.
 */ 
function sharethis_rmtc_form($form, &$form_state) {
	$settings = variable_get('sharethis_rmtc_settings');


	$options = array(
		'1' => t('yes'),
		'0' => t('no'), 
	);

	$form['sharethis_rmtc_facebook'] = array(
		'#type' => 'radios',
		'#title' => t('Display Facebook button ?'),
		'#options' => $options,
		'#description' => t('Would you like to display Facebook button ?'),
		'#default_value' => $settings['facebook'],
	);

	$options = array(
	'1' => t('yes'),
	'0' => t('no'), 
	);

	$form['sharethis_rmtc_twitter'] = array(
		'#type' => 'radios',
		'#title' => t('Display Twitter button ?'),
		'#options' => $options,
		'#description' => t('Would you like to display Twitter button ?'),
		'#default_value' => $settings['twitter'],
	);

	$form['sharethis_rmtc_mail_subject'] = array(
	'#type' => 'textfield',
	'#title' => t('Mail subject'),
	'#required' => TRUE,
	'#default_value' => $settings['mail_subject'],
	'#description' => t('Define mail subject'),
	);

	$options = array(
	'1' => t('yes'),
	'0' => t('no'), 
	);

	$form['sharethis_rmtc_mail'] = array(
		'#type' => 'radios',
		'#title' => t('Display Mail button ?'),
		'#options' => $options,
		'#description' => t('Would you like to display Mail button ?'),
		'#default_value' => $settings['twitter'],
	);

	$options = array(
	'1' => t('yes'),
	'0' => t('no'), 
	);

	$form['sharethis_rmtc_print'] = array(
		'#type' => 'radios',
		'#title' => t('Display Print button ?'),
		'#options' => $options,
		'#description' => t('Would you like to display Print button ?'),
		'#default_value' => $settings['print'],
	);
	
	// Submit button
	$form['submit'] = array(
		'#type' => 'submit',
		'#value' => t('Save settings'),
	);
	
	return $form;	
}

/**
 * Save variables
 */
 function sharethis_rmtc_form_submit($form, &$form_state) {
 	$settings = array(
	 	'facebook' => $form_state['values']['sharethis_rmtc_facebook'],
	 	'twitter' => $form_state['values']['sharethis_rmtc_twitter'],
	 	'mail' => $form_state['values']['sharethis_rmtc_mail'],
	 	'print' => $form_state['values']['sharethis_rmtc_print'],
	 	'mail_subject' => $form_state['values']['sharethis_rmtc_mail_subject'],
 	);
 	variable_set('sharethis_rmtc_settings', $settings);

 	drupal_set_message(t('The settings have been saved'));
 }