CSE 30331 Fall 2015 - Assignments
=================================

This document will walk you through the process of:

1. Setting up a [Bitbucket] account if you do not already have one.

2. Associating your [Notre Dame] email address with your [Bitbucket] account if
   it isn't already.

3. Forking this repository to create a private copy.

4. Configuring the privacy and access controls of the forked repository.

5. Cloning the remote [Git] Repository from [Bitbucket] to a local workspace.

[Bitbucket]:	https://bitbucket.org
[Notre Dame]:	http://www.nd.edu
[unlimited academic plan]:  https://bitbucket.org/plans/
[cse-30331-fa15 Bitbucket]: https://bitbucket.org/CSE-30331-FA15/cse-30331-fa15
[Git]:	https://git-scm.com/

1. Setting Up Account
=====================

* First, open up your web browser and go to http://bitbucket.org/, and click on
  the **Get started** on the upper right-hand corner:

    ![Bitbucket - Get started](http://www3.nd.edu/~pbui/teaching/cse.34331.fa15/static/img/bitbucket_get_started.png)

* Next, you are to fill out the **Sign up** form with your information.  You
  can use any **Username** and **Password**, but we recommend that your
  **Username** be your [Notre Dame] NetID if possible.  Likewise, we recommend 
  that you use your [Notre Dame] email address, which will give you access to 
  the [unlimited academic plan].

    ![Bitbucket - Sign Up](http://www3.nd.edu/~pbui/teaching/cse.34331.fa15/static/img/bitbucket_signup.png)

* [Bitbucket] will now ask if you wish to create a tutorial repository.  You
  can simply click on **No thanks** to skip this and move on to the dashboard
  of your new [Bitbucket] account.

2. Associating Email Address
============================

If you have a [Bitbucket] account but have not associated it with your
[Notre Dame] email address, you may wish to do so in order to get the
[unlimited academic plan].

* After signing into [Bitbucket], you should be taken to your profile
  dashboard.  Click on either the **Manage Account** button in the upper
  right-hand corner to access your account settings or from the drop-down menu
  under your profile icon.

    ![Bitbucket - Manage](http://www3.nd.edu/~pbui/teaching/cse.34331.fa15/static/img/bitbucket_manage.png)

* Next, click on the **Email Addresses** link on the left-hand side of the
  page.  This should show the panel with all the email addresses associated
  with your [Bitbucket] account.

    ![Bitbucket - Email](http://www3.nd.edu/~pbui/teaching/cse.34331.fa15/static/img/bitbucket_email.png)

    If your [Notre Dame] is not there, you can go ahead and enter it in and
    press the **Add** button.  This will send an email confirmation to your
    mailbox.

* Go to your [Notre Dame] email and click on the confirmation email from
  [Bitbucket] to unlock the [unlimited academic plan].

3. Forking the Repository
=========================

To fork this repository, first navigate to the [cse-30331-fa15 Bitbucket]:

    https://bitbucket.org/CSE-30331-FA15/cse-30331-fa15

* On the [cse-30331-fa15 Bitbucket] page, expand the left sidebar menu by
  clicking on the **>>** chevron on the bottom left-hand corner to expose the
  menu and the click on the **Fork** link.

    ![Bitbucket - Fork](http://www3.nd.edu/~pbui/teaching/cse.34331.fa15/static/img/bitbucket_fork.png)

    If you are not signed in already, [Bitbucket] will request that you login
    using the username and password you registered previously.

* Once you are signed in (or if you are already signed in), [Bitbucket] will
  take you to the **Fork** dialog.  Leave the **Name** alone and enter in
  "Assignments for _Full Name_ (_NetID_)" into the **Description** field 
  (replacing _Full Name_ and _NetID_ with your name and NetID).

The following two settings are very important in order for you to get credit for your work!

* Ensure that you check the **This is a private repository** box.

* Ensure that you check the **Inherit repository user/group permissions** box.

    ![Bitbucket - Fork Dialog](http://www3.nd.edu/~pbui/teaching/cse.34331.fa15/static/img/bitbucket_fork_dialog.png)

    Once you have filled out the information, click on the **Fork repository**
    button to complete the process.

4. Configuring Privacy and Access Controls
==========================================

To verify the privacy and access controls of your new private repository, go to
the [Bitbucket] page of your clone.

* Click on the **Settings** button (the gear) on the left-hand side.  This
  will take you to the settings for the repository.  Verify that the
  **Description** field is filled out correctly.  Likewise, verify that the
  **This is a private repository box** Access level is checked.

    ![Bitbucket - Repository Details](http://www3.nd.edu/~pbui/teaching/cse.34331.fa15/static/img/bitbucket_repo_details.png)

* Next, click on the **Access Management** link on the left-hand side.  Verify
  that the only users are yourself and [Data Structures Fall
  2015](https://bitbucket.org/CSE-30331-FA15/).

    If [Data Structures Fall
  2015](https://bitbucket.org/CSE-30331-FA15/) is missing, add it by entering in a **Username** of
    **CSE-30331-FA15**.  Ensure that this user has either **WRITE** or
    **ADMIN** rights.

    ![Bitbucket - Access](http://www3.nd.edu/~pbui/teaching/cse.34331.fa15/static/img/bitbucket_repo_access.png)

5. Cloning the Repository
=========================

Clone your repository onto your own computer, or into your home directory on student0x.cse.nd.edu. The easiest way to do this is to click on **Clone**:

![Bitbucket - Clone](http://www3.nd.edu/~pbui/teaching/cse.34331.fa15/static/img/bitbucket_clone.png)

Copy the command and paste it into the shell. The repository will be cloned into the directory `cse-30331-fa15` under your current working directory.
