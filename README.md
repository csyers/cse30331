CSE 30331 Fall 2015 - Assignments
=================================

This document will walk you through the process of:

1. Setting up a [Bitbucket] account if you do not already have one.

2. Associating your [Notre Dame] email address with your [Bitbucket] account if
   it isn't already.

3. Forking this repository to create a private copy.

4. Configuring the privacy and access controls of the forked repository.

5. Cloning the remote [Git] Repository from [Bitbucket] to a local workspace.

6. Synchronizing your forked [Git] repository with the upstream class
   repository.

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

If you are experiencing the following error on the student0x.cse.nd.edu machines:

    $ git clone https://dmcdomers@bitbucket.org/dmcdomers/cse-30331-fa15.git
    Initialized empty Git repository in /afs/nd.edu/user99/dmcdomers/cse-30331-fa15/.git/

    (gnome-ssh-askpass:7477): Gtk-WARNING **: cannot open display:

You will need to unset the **SSH_ASKPASS** environment variable:

    $ unsetenv SSH_ASKPASS  # For csh

    $ unset SSH_ASKPASS     # For bash

Once you unset the **SSH_ASKPASS** variable, you should now perform the **git
clone** command.

6. Synchronizing the Repository
===============================

Every once in a while, the course instructors will push new files or changes to
the [cse-30331-fa15 Bitbucket] repository.  Because you forked this original
repository, the [cse-30331-fa15 Bitbucket] is considered your **upstream**.  To
retrieve these new modifications from the **upstream** repository, you can
either use the web interface provided by [Bitbucket]:

* Go to your private repository and check on the upper right-hand side of the
  overview page if there is a notification that says something like: "This fork
  is X commits behind CSE-30331-FA15/cse-30331-fa15. Sync now".  If so, then
  there are changes from the **upstream** repository that you can pull into
  your private repository.

    ![Bitbucket - Sync](http://www3.nd.edu/~pbui/teaching/cse.34331.fa15/static/img/bitbucket_sync.png)

* To proceed in synchronizing your private repository with **upstream**, click
  on the **Sync now** link.  This will take you do a dialog that looks like the
  following:

    ![Bitbucket - Dialog](http://www3.nd.edu/~pbui/teaching/cse.34331.fa15/static/img/bitbucket_sync_dialog.png)

    Go ahead and click on **Sync** to attempt the synchronization.

* If all goes well, then [Bitbucket] will take you to a summary page of the
  synchronization (also known as a merge) as shown below:

    ![Bitbucket - Merge](http://www3.nd.edu/~pbui/teaching/cse.34331.fa15/static/img/bitbucket_sync_merge.png)

You can now retrieve these changes to your local repository (ie. on
student0x.cse.nd.edu), but doing a **git pull** in the terminal.

If [Bitbucket] detects the possibility of **merge conflicts**, or if you wish
to do the synchronization manually, you can instead perform the following steps:

* First, you need to add the **upstream** repository to your local [Git] repository:

        $ git remote add upstream https://bitbucket.org/CSE-30331-FA15/cse-30331-fa15

* Once that is done, everytime you wish to update your local repository with
  the changes from **upstream**, you can do the following:
  
        $ git fetch upstream
        $ git merge upstream/master
