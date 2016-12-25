


int main(void)
{
    open_file_and_validation();

    collect_meta_data();
    {
        create_meta_data_structure();

        {
            copy_meta_data_from_file_in_to_buffer();
            parse_and_store_meta_data_fields_from_buffer_in_to_structure();
        }

        or

        {
            create_ref_meta_data();
        }
    }

    collect_contacts_from_file();
    {
        in loop
        {
            copy__each_contact_from_file_to_buffer();
            create_contact_structure();
            parse_and_store_contact_fields_from_buffer_in_to_contact_structure();
        }
    }

    main_menu();
    {
        add_contact_menu();
        view_contact_menu();
        back();
    }

    add_contact_menu();
    {
        check_A_B_full_flag();
        create_and_append_contact_structure();
        prompt_fields_and_store_data_in_to_contact_structure();
        {
            read_field_from_user();
            check_:back_in_read_field();
            validate_read_field();
        }
        back();
    }

    view_contact_menu();
    {
        check_A_B_empty_flag();
        prompt_search_options();
        check_:back_in_read_field();
        {
            switch(search_options)
            {
                case first_name:
                    generic_search_and_set_view_index_flag_high(first_name);
                    break;
                case last_name:
                    generic_search_and_set_view_index_flag_high(last_name);
                    break;
                case phone_number:
                    generic_search_and_set_view_index_flag_high(phone_number);
                    break;
                case group:
                    generic_search_and_set_view_index_flag_high(group);
                    break;
                case nick_name:
                    generic_search_and_set_view_index_flag_high(nick_name);
                    break;
                case back_to_prev_menu:
                    break;
            }

            display_found_contacts();
            prompt_action_menu();
        }
    }

    prompt_action_menu();
    {
        edit_contact();
        delete_contact();
        back();
    }

    edit_menu();
    {
        create_temporary_copy_of_contact();
        diplay_temporary_copy_of_contact();
        in loop;
        {
            prompt_and_read_fields();
            check_:back_in_read_field();
            validate_contact
            prompt_exit();
        }
        write_temporary_copy_to_original_contact();
        free_tempory_copy_memory();

        or
            
        free_tempory_copy_memory();

        










