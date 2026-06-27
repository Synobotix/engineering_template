# HW Bring-Up

<!--
Progressive power-up procedure and initial functional tests for hardware.
Follow sequentially — do not skip steps.
Each step has a binary success criterion (PASS / FAIL).
-->

## Prerequisites

- [ ] PCB assembled and visually inspected
- [ ] BOM verified against schematic (all components correct)
- [ ] Tools: lab power supply (current limiting), multimeter, oscilloscope
- [ ] Initial firmware compiled and ready to flash

---

## Step 1 — Visual inspection

| Check point                          | Method       | Expected result    | PASS / FAIL |
|--------------------------------------|--------------|--------------------|-------------|
| No solder bridges                    | Loupe × 10   | No bridges         |             |
| Electrolytic capacitor polarity      | Visual       | Correct            |             |
| IC orientation                       | Visual (pin 1)| Correct           |             |
| No missing components                | Visual vs BOM| All present        |             |

## Step 2 — Continuity test (unpowered)

| Test                                 | Method            | Expected result  |
|--------------------------------------|-------------------|------------------|
| Short circuit VCC → GND             | Ohmmeter TP1→TP2  | > 1 kΩ           |
| Ground plane continuity              | Ohmmeter GND→GND  | < 1 Ω            |

## Step 3 — First power-up (current limiting)

> **Supply**: V = … V, I limit = … mA

| Measurement                          | Test point | Expected value  | Tolerance | PASS / FAIL |
|--------------------------------------|------------|-----------------|-----------|-------------|
| VCC_3V3 rail voltage                 | TP1        | 3.3 V           | ± 2 %     |             |
| Current draw at rest                 | Lab supply | < … mA          | —         |             |
| VCC_5V voltage (if applicable)       | TP…        | 5 V             | ± 2 %     |             |

## Step 4 — Firmware programming

```sh
# Example with ST-Link / OpenOCD
openocd -f interface/stlink.cfg -f target/stm32g0x.cfg \
  -c "program firmware.elf verify reset exit"
```

- [ ] Flash successful (no errors)
- [ ] Status LED / heartbeat visible (if implemented)

## Step 5 — Basic functional tests

| Function                       | Method          | Success criterion                       | PASS / FAIL |
|-------------------------------|-----------------|-----------------------------------------|-------------|
| UART debug communication       | Serial terminal | Boot messages received without corruption|            |
| Main sensor reading            | Firmware log    | Value within expected range             |             |
| External interface (CAN/ETH/…) | Analyser        | Correct frames                          |             |

## Step 6 — Preliminary EMC checks

| Test                            | Tool          | Criterion              |
|---------------------------------|---------------|------------------------|
| Power supply noise              | Oscilloscope  | Vripple < … mV         |
| Radiated emissions (qualitative)| Near antenna  | No abnormal spectral lines |

## Results record

| Step | Date | Technician | Overall result | Anomalies |
|------|------|------------|----------------|-----------|
| 1    |      |            | PASS / FAIL    |           |
| 2    |      |            | PASS / FAIL    |           |
| 3    |      |            | PASS / FAIL    |           |
| 4    |      |            | PASS / FAIL    |           |
| 5    |      |            | PASS / FAIL    |           |

## Reference

- Schematics: [../design/hw-schematics.md](../design/hw-schematics.md)
- Test points: [../implementation/manufacturing.md](../implementation/manufacturing.md)
- Verification plan: [verification-plan.md](verification-plan.md)
