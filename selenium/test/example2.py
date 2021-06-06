"""Streaming.
    python -m examples.streaming
"""
import asyncio

from pydantic import BaseSettings

import tinvest as ti

async def main() -> None:
    async with ti.Streaming('t.PLwZb6SRcQDAMlDbxpKZ1ScJx3W22Z34os4LHd2QpnHr4YM5eSDHp9Xb3N3RlToH8NzbKLQoL-uUXKkg41Qh4Q') as streaming:
        await streaming.candle.subscribe('BBG0013HGFT4', ti.CandleResolution.min1)
        await streaming.orderbook.subscribe('BBG0013HGFT4', 5)
        await streaming.instrument_info.subscribe('BBG0013HGFT4')
        async for event in streaming:
            print(event)  # noqa:T001


try:
    asyncio.run(main())
except KeyboardInterrupt:
    pass