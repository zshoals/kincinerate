let project = new Project('New Project');

project.addFile('Sources/**');
project.setDebugDir('Deployment');

//project.addDefine('BURN_LOGGING_DISABLED');

resolve(project);
