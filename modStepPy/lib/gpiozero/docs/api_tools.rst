=========================
API - Device Source Tools
=========================

.. module:: gpiozero.tools

GPIO Zero includes several utility routines which are intended to be used with
the :doc:`source_values` attributes common to most devices in the library.
These utility routines are in the ``tools`` module of GPIO Zero and are
typically imported as follows::

    from gpiozero.tools import scaled, negated, all_values

Given that :attr:`~gpiozero.SourceMixin.source` and
:attr:`~gpiozero.ValuesMixin.values` deal with infinite iterators, another
excellent source of utilities is the :mod:`itertools` module in the standard
library.

.. warning::

    While the devices API is now considered stable and won't change in
    backwards incompatible ways, the tools API is *not* yet considered stable.
    It is potentially subject to change in future versions. We welcome any
    comments from testers!

Single source conversions
=========================

.. autofunction:: absoluted

.. autofunction:: booleanized

.. autofunction:: clamped

.. autofunction:: inverted

.. autofunction:: negated

.. autofunction:: post_delayed

.. autofunction:: post_periodic_filtered

.. autofunction:: pre_delayed

.. autofunction:: pre_periodic_filtered

.. autofunction:: quantized

.. autofunction:: queued

.. autofunction:: smoothed

.. autofunction:: scaled

Combining sources
=================

.. autofunction:: all_values

.. autofunction:: any_values

.. autofunction:: averaged

.. autofunction:: multiplied

.. autofunction:: summed

Artificial sources
==================

.. autofunction:: alternating_values

.. autofunction:: cos_values

.. autofunction:: ramping_values

.. autofunction:: random_values

.. autofunction:: sin_values
