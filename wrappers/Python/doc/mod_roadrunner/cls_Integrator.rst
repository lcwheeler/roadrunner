Integrator Class
________________

.. class:: roadrunner.Integrator

    An integrator is used to describe the method of carrying out a mathematical integration. Currently, libRoadRunner supports cvode, gillespie, rk4 and rk45 solvers. For solver related methods, refer to http://sys-bio.github.io/roadrunner/python_docs/api_reference.html#solver-class. The following methods are supported by all the Integrators.


.. method:: Integrator.getIntegrationMethod()

    Gets the method of integration as an integer. (0-Deterministic, 1-Stochastic, 2-Hybrid, 3-Other).


.. method:: Integrator.getListener()

    Gets the integrator listener.


.. method:: Integrator.integrate(t0, hstep)

    Main integration routine.

    :param double t0: start time
    :param double hstep: time step size


.. method:: Integrator.loadSBMLSettings(filename)

    Load an SBML settings file and apply the configuration options.
    Note: Can assign relative and absolute tolerances.

    :param string filename: A string which may be a local path, URI or contents of an SBML document.


.. method:: Integrator.restart(t0)

    Reset time to zero and reinitialize model. Applies events which occur before time zero. Reinitializes CVODE and the executable model.

    :param double t0: start time


.. method:: Integrator.setListener(listener)

    Sets the integrator listener.

    :param listener: Swig Object of type 'rr::PyIntegratorListenerPtr *'


.. method:: Integrator.tweakTolerances()

    Fix tolerances for SBML tests. In order to ensure that the results of the SBML test suite remain valid, this method enforces a lower bound on tolerance values. Sets minimum absolute and relative tolerances to Config::CVODE_MIN_ABSOLUTE and Config::CVODE_MIN_RELATIVE respectively.


CVODE
-----

   CVODE is a deterministic ODE solver from the SUNDIALS suite of timecourse integrators. It implements an Adams-Moulton solver for non-stiff problems and a backward differentiation formula (BDF) solver for stiff problems.


.. attribute:: Integrator.absolute_tolerance

    Specifies the scalar absolute tolerance. CVODE calculates a vector of error weights which is used in all error and convergence tests. The weighted RMS norm for the absolute tolerance should not become smaller than this value. Default value is Config::CVODE_MIN_ABSOLUTE.


.. attribute:: Integrator.initial_time_step

    Specifies the initial time step size. If inappropriate, CVODE will attempt to estimate a better initial time step. Default value is 0.0


.. attribute:: Integrator.maximum_adams_order

    Specifies the maximum order for Adams-Moulton intergration. This integration method is used for non-stiff problems. Default value is 12.


.. attribute:: Integrator.maximum_bdf_order

    Specifies the maximum order for Backward Differentiation Formula integration. This integration method is used for stiff problems. Default value is 5.


.. attribute:: Integrator.maximum_num_steps

    Specifies the maximum number of steps to be taken by the CVODE solver in its attempt to reach tout. Default value is 20000.


.. attribute:: Integrator.maximum_time_step

    Specifies the maximum absolute value of step size allowed. If inappropriate, CVODE will attempt to estimate a better maximum time step. Default value is 0.0.


.. attribute:: Integrator.minimum_time_step

    Specifies the minimum absolute value of step size allowed. If inappropriate, CVODE will attempt to estimate a better maximum time step. Default value is 0.0.


.. attribute:: Integrator.multiple_steps

    Perform a multiple time step simulation. Default value is false.


.. attribute:: Integrator.relative_tolerance

    Specifies the scalar relative tolerance. CVODE calculates a vector of error weights which is used in all error and convergence tests. The weighted RMS norm for the relative tolerance should not become smaller than this value. Default value is Config::CVODE_MIN_RELATIVE.


.. attribute:: Integrator.stiff

    Specifies whether the integrator attempts to solve stiff equations. Ensure the integrator can solver stiff differential equations by setting this value to true. Default value is true.


.. attribute:: Integrator.variable_step_size

    Perform a variable time step simulation. Enabling this setting will allow the integrator to adapt the size of each time step. This will result in a non-uniform time column. Default value is flase.


Gillespie
---------

    RoadRunner's implementation of the standard Gillespie Direct Method SSA. The granularity of this simulator is individual molecules and kinetic processes are stochastic. Results will, in general, be different in each run, but a sufficiently large ensemble of runs should be statistically correct.


.. attribute:: Integrator.initial_time_step

    Specifies the initial time step size. If inappropriate, CVODE will attempt to estimate a better initial time step. Default value is 0.0


.. attribute:: Integrator.maximum_time_step

    Specifies the maximum absolute value of step size allowed. If inappropriate, CVODE will attempt to estimate a better maximum time step. Default value is 0.0.


.. attribute:: Integrator.minimum_time_step

    Specifies the minimum absolute value of step size allowed. If inappropriate, CVODE will attempt to estimate a better maximum time step. Default value is 0.0.


.. attribute:: Integrator.nonnegative

    Prevents species amounts from going negative during a simulation. Default value is false.


.. attribute:: Integrator.seed

   Set the seed into the random engine.


.. attribute:: Integrator.variable_step_size

    Perform a variable time step simulation. Enabling this setting will allow the integrator to adapt the size of each time step. This will result in a non-uniform time column. Default value is flase.


RK4
---
    
    Runge-Kutta methods are a family of algorithms for solving ODEs. They have considerably better accuracy than the Euler method. This integrator is a standard 4th order Runge-Kutta solver.


RK45
----

    RoadRunner's implementation of the standard Gillespie Direct Method SSA. The granularity of this simulator is individual molecules and kinetic processes are stochastic. Results will, in general, be different in each run, but a sufficiently large ensemble of runs should be statistically correct.


.. attribute:: Integrator.epsilon

    Specifies the maximum error tolerance allowed. Default value is 1e-12.


.. attribute:: Integrator.maximum_time_step

    Specifies the maximum absolute value of step size allowed. If inappropriate, CVODE will attempt to estimate a better maximum time step. Default value is 0.0.


.. attribute:: Integrator.minimum_time_step

    Specifies the minimum absolute value of step size allowed. If inappropriate, CVODE will attempt to estimate a better maximum time step. Default value is 0.0.


.. attribute:: Integrator.variable_step_size

    Perform a variable time step simulation. Enabling this setting will allow the integrator to adapt the size of each time step. This will result in a non-uniform time column. Default value is flase.

