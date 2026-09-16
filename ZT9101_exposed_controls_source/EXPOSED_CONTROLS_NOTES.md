# Exposed controls notes

## Scope

This revision exposes the controls that are actually backed by the current
Linux driver's configuration parser and `local_info_st` state, rather than
inventing configuration keys with no implementation behind them.

## Added/confirmed configuration surface

- Firmware paths and interface names
- Channel plan, channel and bandwidth
- Work mode and SSID (where the corresponding build option is enabled)
- Wireless mode and short-GI policy
- TX/RX block acknowledgement and A-MPDU controls
- Scan dwell/probe/active/queue/TTL controls
- ARS policy
- RF table selectors and requested TX power
- VCO current/calibration selector
- RTS/fragmentation and virtual-carrier-sense controls
- TX data reporting
- SM power-save, station sleep, LDPC and TX-STBC capability controls
- HT MCS ceiling
- WLAN status guard
- SDIO clock power-save

## Important implementation detail

`txpower_dbm` is not a direct linear DAC value in the current driver. The
parser maps the requested value to the existing calibrated low/medium/high
RF table selection and retains the requested dBm value for cfg80211/runtime
visibility. The current source clamps the user-facing value to 0..30 dBm.

`vco_cur` accepts the existing 0..32 range and the legacy `0xff` calibration
sentinel. Values outside that range are deliberately not turned into
unrestricted raw RF writes.

## Experimental section

The bottom of `wifi.cfg` contains commented examples for the controls that
could affect RF calibration, PHY advertisement, aggregation stress, or
unstable interface modes. They are intentionally disabled rather than silently
removed.
